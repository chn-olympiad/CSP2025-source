#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int i1,i2,i3,i;
};
struct bc{
	int x,i;
}b[N],c[N];
int n,T,ans;
node a[N];
bool vis[N];
bool cmp1(node x,node y){
	return x.i1>y.i1;
}
void dfs(int a1,int a2,int a3,int x,int t){
	if(t-1==n){
		ans=max(ans,x);
		return;
	}
	if(a1<n/2)dfs(a1+1,a2,a3,x+a[t].i1,t+1);
	if(a2<n/2)dfs(a1,a2+1,a3,x+a[t].i2,t+1);
	if(a3<n/2)dfs(a1,a2,a3+1,x+a[t].i3,t+1);
}
void dfsb(int a1,int a2,int a3,int x,int t){
	if(t-1==n){
		ans=max(ans,x);
		return;
	}
	if(a1<n/2)dfs(a1+1,a2,a3,x+a[t].i1,t+1);
	if(a2<n/2)dfs(a1,a2+1,a3,x+a[t].i2,t+1);
}
bool fxx(){
	for(int i=1;i<=n;i++)
		if(!vis[i])return false;
	return true;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(vis,false,sizeof(vis));
		ans=0;
		cin>>n;
		bool TSa=true,TSb=true;
		for(int i=1;i<=n;i++){
			a[i].i=i;
			cin>>a[i].i1>>a[i].i2>>a[i].i3;
			if(a[i].i2||a[i].i3)TSa=false;
			if(a[i].i3)TSb=false;
		}
		if(TSa){
			int sum=0;
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++)sum+=a[i].i1;
			cout<<sum<<"\n";
			continue;
		}
		if(TSb){
			dfsb(0,0,0,0,1);
			cout<<ans<<"\n";
			continue;
		}
		dfs(0,0,0,0,1);
		cout<<ans<<"\n";
	}
	return 0;
}
