#include <bits/stdc++.h>
using namespace std;
const int ANSq = 998244353;
const int MAXN = 5005;
int all = 0,ans = 0,maxa = -114514,maxb = -1919810,n,a[MAXN],q,now[MAXN];
void chackab(int test,int t){
	now[t] = test;
	for (int k = 0;k < t - 1;k++){
		if(now[k] >= maxa){
			maxb = maxa;
			maxa = now[k];
		}else if (now[k] >= maxb){
			maxb = now[k];
		}
	}
}
void dfs(int l,int time){
	if (time == 0){
		if (all > 2 * maxa){
			ans++;
			ans %= ANSq;
			//cout << all << " " << maxa << endl;
		}
		return;
	}
	for (int i = l;i < n;i++){
		chackab(a[i],q - time);
		all += a[i];
		dfs(l+1,time-1);
		now[time + 1] = 0;
		all -= a[i];
	}
	now[time] = 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 0;i < n;i++) cin >> a[i];
	for (q = 3;q <= n;q++){
		dfs(0,q);
	}
	cout << ans;
	return 0;
}
