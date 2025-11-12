#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[25],vis[25],ans;
string a;
void dfs(int k,int e,int sum){
	if(sum+n-k+1<m) return;
	if(k==n+1){
		if(sum>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
	   if(vis[i]) continue;
	   vis[i]=1;
	   int s1=sum,s2=e;
	   if(c[i]>e&&a[k-1]=='1')
	   s1++;
	   else s2++;
	   dfs(k+1,s2,s1);
	   vis[i]=0;
    }
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<=n;i++)
	cin>>c[i];
	dfs(1,0,0);
	cout<<ans;
}
