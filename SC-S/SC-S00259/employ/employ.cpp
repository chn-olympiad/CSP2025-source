#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
const long long M=998244353;
long long n,m,ans;
int vis[N];
string S;
long long c[N];
void dfs(long long x,long long l,long long sum,long long p){
	if(sum==n){
		if(p==m) ans++;
//		cout<<ans<<' ';
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(S[sum]=='0'||l>=c[i]){
				dfs(i,l+1,sum+1,p);	
			}
			else dfs(i,l,sum+1,p+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld%lld",&n,&m);
	cin>>S;
	for(long long i=1;i<=n;i++) scanf("%lld",&c[i]);
	for(long long i=1;i<=n;i++){

		vis[i]=1;
		if(S[i-1]=='0'||c[i]==0){
			dfs(i,1,1,0);	
		}
		else dfs(i,0,1,1);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}