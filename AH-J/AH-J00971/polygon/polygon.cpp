#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int b[100005];
long long c[100005];
bool vis[1000005];
int ansx=0;
void dfs(int x,int s,int p){
	c[s]=a[x];
	if(s==p){
		long long ans=0,ans2=0;
		for(int i=1;i<=s;i++){
			ans+=c[i];
			ans2=max(ans2,c[i]);
		}
		ans2*=2;
		if(ans>ans2) ansx++,ans%=998244353;
		return ;
	}
	for(int i=x+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(i,s+1,p);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s=0;
	for(int i=3;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=n;j++){
			ansx=0;
			dfs(j,1,i);
			s+=ansx;
			s%=998244353;
		}
	}
	cout<<s<<endl;
	return 0;
}
