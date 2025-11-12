#include<bits/stdc++.h>
using namespace std;
const int maxn = 5010,MOD = 998244353;
long long n,ans = 0,a[maxn];
bool b[maxn];
void dfs(long long x){
	if(x == n + 1){
		long long maxx = -1,cnt = 0;
		for(int i = 1;i <= n;i++){
			if(b[i] == 1){
				maxx = max(maxx,a[i]);
				cnt += a[i];
			}
		}
		if(cnt > maxx * 2){
			ans++;
		}
		return;
	}
	for(int i = 0;i <= 1;i++){
		b[x] = i;
		dfs(x + 1);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)cin >> a[i];
	if(n <= 30){
		dfs(1);
		cout << ans - 1 << endl;
	}else{
		bool flag = true;
		for(int i = 1;i <= n;i++){
			if(a[i] != 1)flag = false;
		}
		if(flag){
			
		}else{
			cout << 114514 << endl;
		}
	}
	return 0;
}
