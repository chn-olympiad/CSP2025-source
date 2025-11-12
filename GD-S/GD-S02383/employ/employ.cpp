#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int a,b,d[1000005],e,pd,pd1[1000005],ans;
char c[1000005];
void dfs(int n,int sum){
	if(n == a+1){
		if(sum >= b){
			ans++;
			ans %= mod;
		}
		return ;
	}
	for(int i = 1; i <= a; i++){
		if(pd1[i] == 0){
			pd1[i] = 1;
			if(c[n] == '1' && n - sum - 1 < d[i]){
				dfs(n+1,sum+1);
			}
			else{
				dfs(n+1,sum);
			}
			pd1[i] = 0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> a >> b;
	for(int i = 1; i <= a; i++){
		cin >> c[i];
		if(c[i] == '0'){
			pd = 1;
		}
		else{
			e++;
		}
	}
	if(pd == 0){
		ans = 1;
		for(int i = 1; i <= a; i++){
			ans *= i;
			ans %= mod;
		}
		cout << ans;
		return 0;
	}
	if(e < b){
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= a; i++){
		cin >> d[i];
	}
	dfs(1,0);
	cout << ans;
	return 0;
} 
