#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
const int N=1e6+20;
struct node{
	int v;
	int u;
	int w;
	int xc;
	int js;
}mp[N];
int f[N],vis[N];
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
bool cmp(node x,node y){
	return x.w<y.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.ans","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int v1,u1,w1;
		cin>>v1>>u1>>w1;
		mp[i].v=v1;
		mp[i].u=u1;
		mp[i].w=w1;
		mp[i].xc=0;
		mp[i].js=0;
	}
	int cnt=1;
	for(int i=1;i<=k;i++){
		int p;
		cin>>p;
		
		for(int j=1;j<=n;j++){
			int w1;
			cin>>w1;
			vis[i]=1;
			for(int s=j+1;s<=n;s++){
				
				mp[n+cnt++].v=j;
				mp[n+cnt].u=s;
				mp[n+cnt].w=w1+mp[n+cnt-(s-j)].w;
				mp[n+cnt].xc=i;
				mp[n+cnt].js=p;
			}
		}
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=cnt;i++){
		f[i+n]=i+n;
	}
	sort(mp+1,mp+m+cnt,cmp);
	for(int i=1;i<=m+cnt;i++){
		if(find(mp[i].v)!=find(mp[i].u)){
			if(mp[i].xc>0&&vis[mp[i].xc]==1){
				ans+=mp[i].js;
				vis[mp[i].xc]=0;
			}
			f[mp[i].v]=f[mp[i].u];
			ans+=mp[i].w; 
		}
	}
	cout<<ans;
	return 0;
} 
