#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int c[15],a[15][10005];
int fa[1000005];
struct rd{
	int u,v,w;
}rds[1000005];

bool cmp(rd a,rd b){
	return a.w<b.w;
}

int gtfa(int a){
	if(fa[a]==a) return a;
	int b=gtfa(fa[a]);
	fa[a]=b;
	return b;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>rds[i].u>>rds[i].v>>rds[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			fa[j]=j;
		}
	}
	if(k==0){
		sort(rds+1,rds+m+1,cmp);
		int ans=0;
		for(int now=1;now<=m;now++){
			if(gtfa(rds[now].u)!=gtfa(rds[now].v)){
				fa[gtfa(rds[now].v)]=gtfa(rds[now].u);
				ans+=rds[now].w;
			}
		}
		cout<<ans;
		return 0;
	}
	cout<<0;	
	return 0;
}
