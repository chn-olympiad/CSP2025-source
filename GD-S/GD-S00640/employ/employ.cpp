#include<iostream>
#include<cstring>
using namespace std;
const int N=505;
const int MOD=998244353;
int n,m;
string s;
int c[N];
bool vis[N];
long long fac[N];
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD;
}
long long dfs(int p,int h,int k){
	if(k==m) return fac[n-p+1];
	if(p==n+1) return 0;
	long long res=0;
	for(int i=1;i<=n;i++)
	if(!vis[i]){
		if(s[p-1]=='0'){
			vis[i]=1;
			res=(res+dfs(p+1,h+1,k))%MOD;
			vis[i]=0;
		}
		else if(c[i]<=h){
			vis[i]=1;
			res=(res+dfs(p+1,h+1,k))%MOD;
			vis[i]=0;
		}
		else if(s[p-1]=='1'){
			vis[i]=1;
			res=(res+dfs(p+1,h,k+1))%MOD;
			vis[i]=0;
		}
	}
	return res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	init(n);
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	cout<<dfs(1,0,0);
	return 0;
}
