#include<bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int kmaxN = 5010;
int n;
long long a[kmaxN],chen[kmaxN],ans;
bool vis[kmaxN];
void dfs(long long nl,long long ml,int num,int poss){
	if(num >= 3 && nl > 2*ml){
		ans = (ans+1)%MOD;
	}
	if(num > n) return;
	for(int i = poss+1;i <= n;i++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(nl+a[i],max(a[i],ml),num+1,i);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f = 1;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] > 1) f = 0;
 	}
 	chen[0] = 1;chen[1] = 1;
 	for(int i = 2;i <= n;i++){
 		chen[i] = (chen[i-1]*i)%MOD;
	}
 	for(int i = 3;i <= n;i++){
 		long long chu = (chen[i] * chen[n-i]) % MOD;
 		ans+=chen[n] / chu;
	}
	if(f){
		cout<<ans;
	}else{
		ans = 0;
		sort(a+1,a+n+1);
		dfs(0,0,0,0);
		cout<<ans;
	}
	return 0;
} 
