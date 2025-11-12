#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5005],vis[5005];
long long cnt=0;
void dfs(int k,int s,int p,int ma,int su){
	if(p==s&&su>2*ma){
//		for(int i=1;i<=s;i++){
//			cout<<ans[i]<<" ";
//		}
//		cout<<endl;
		cnt=(cnt+1)%mod;
		return;
	}
	if(k==n+1) return;
	if(!vis[k]){
		vis[k]=1;
		dfs(k+1,s,p+1,max(ma,a[k]),su+a[k]);
		vis[k]=0;
	}
	dfs(k+1,s,p,ma,su);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(1,i,0,0,0);
	}
	cout<<cnt;
	return 0;
} 
