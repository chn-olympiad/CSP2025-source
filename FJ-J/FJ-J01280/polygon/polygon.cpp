#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5005],vis[5005];
bool check(){
	int s=0,maxx=0;
	for(int i=1;i<=n;i++)
	if(vis[i]==1)s+=a[i],maxx=max(maxx,a[i]);
	return s>maxx*2;
}
void dfs(int num,int dis){
	if(dis>=3&&check())ans=(ans+1)%998244353;
	for(int i=num+1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			dfs(i,dis+1);
			vis[i]=0;
		}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(0,1);
	printf("%d",ans);
	return 0;
}
