#include<bits/stdc++.h>
#define int long long
using namespace std;
struct bian{
	int u;
	int v;
	int w;
};
int n,m,k,cw,fcnt,zhi,ans,fau,fav;
int cnt,g[100],fa[5000005];
bian b[5000005];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void kruskal(){
	while(fcnt!=1&&zhi<=10){
		zhi++;
		fau=find(fa[b[zhi].u]);
		fav=find(fa[b[zhi].v]);
		//cout<<zhi<<" "<<fau<<" "<<fav<<"\n"; 
		if(fau!=fav){
			fa[fau]=fav;
			ans+=b[zhi].w;
			fcnt--;
		}
	}
	return;
}
bool cmp(bian x,bian y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>b[i].u>>b[i].v>>b[i].w;
		cnt++;
		//cout<<b[cnt].u<<" "<<b[cnt].v<<" "<<b[cnt].w<<"\n";
	}
	for(int i=1;i<=k;i++){
		cin>>g[i];
		for(int j=1;j<=n;j++){
			cin>>cw;
			b[++cnt].u=j;b[cnt].v=n+i;b[cnt].w=cw;
		}
	}
	sort(b+1,b+cnt+1,cmp); 
	fcnt=n+k;
	//cout<<fcnt<<"\n";
	//for(int i=1;i<=cnt;i++) cout<<b[i].u<<" "<<b[i].v<<" "<<b[i].w<<" ";
	//cout<<"\n";
	for(int i=1;i<=cnt;i++) fa[i]=i;
	kruskal();
	cout<<ans;
	return 0;
}

