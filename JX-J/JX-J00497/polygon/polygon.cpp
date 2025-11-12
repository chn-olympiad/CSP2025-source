#include <bits/stdc++.h>

#define int long long
using namespace std;
int n,a[5010],maxa,ans,suma,sumb[5010];
bool is = 1;
int jc(int a){
	int ans = 1;
	for(int i = 1;i <= a;i ++){
		ans *= i;
		ans %= 998244353;
	}
	return ans;
}
int solve(int a,int b){
	int tp1 = jc(a),tp2 = jc(a-b),tp3 = jc(b);
	int ans = (tp1 / (tp2 * tp3)) % 998244353;
	return ans;
}
void dfs(int sum,int chnum,int num,int maxt,bool is){
	if(chnum >= 3 && sum > 2 * maxt && is){
		ans ++;
	}
	if(ans >= 998244353) ans %= 998244353;
	if(num >= n + 1) return;
	if(sum + (suma - sumb[num - 1]) <= 2 * maxt) return;
	
	if(chnum >= 3 && sum > 2 * maxt && is){
		int temp11 = 1;
		for(int i = num;i <= n;i ++){
			ans += temp11;
			temp11 *= 2;
			ans %= 998244353;
			temp11 %= 998244353;
		}
		return;
	}
	
	dfs(sum + a[num],chnum + 1,num + 1,max(maxt,a[num]),1);
	dfs(sum,chnum,num + 1,maxt,0);
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		suma += a[i];
		sumb[i] = sumb[i - 1] + a[i];
		if(a[i] != 1) is = 0;
	} 
	if(is){
		int ans = 0;
		for(int i = 3;i <= n;i ++){
			ans += solve(n,i);
			ans %= 998244353;
		}
		cout << ans;
		return 0;
	}
	sort(a + 1,a + n + 1,greater<int>());
	dfs(0,0,1,0,0);
	cout << ans << '\n';
	return 0;
}
/*
begin time 18:30
end time 22:00

rp++
* 6930537
*/
