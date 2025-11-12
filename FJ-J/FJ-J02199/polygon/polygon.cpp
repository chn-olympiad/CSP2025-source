#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 5e3 + 5;
int a[N];
//long long num[505];
bool cmp(int x,int y){
	if(x != y){
		return x < y;
	}
}
int n;
long long ans = 0;
inline void dfs(int step,int sum,int max,int k,bool f){//在第几位，当前最大的那个，边长和边数 
	if(step == n + 1){
		return;
	}
	bool flag = true;
	if(sum > 2 * a[step] && k >= 3){
		if(f){
			ans++;
			ans %= mod;
			
		}
		flag = false;
	}
	//cout << step << " " << sum << " " << max << " " << k << endl;
	dfs(step + 1,sum + a[step + 1],step + 1,++k,true);
	dfs(step + 1,sum,max,k,flag);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n; 
	int tmax = -1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		tmax = max(a[i],tmax);
	}
//	if(tmax == 1){
//		num[1] = 1;
//		for(int i = 2; i <= n; i++){
//			num[i] = num[i - 1] * i;
//			num[i] %= mod;
//		}
//		for(int i = 3; i <= n; i++){
//			long long t = num[n] / num[i] / num[n - i];
//			ans += t;
//			t %= mod;
//		}
//		cout << ans << endl;
//		return 0;	
//	}
	sort(a + 1,a + n + 1,cmp);
//	for(int i = 1; i <= n; i++){
//		sum[i] = sum[i - 1] + a[i];
//	}
	dfs(0,0,0,0,1);
	cout << ans << endl;
	return 0;
}
