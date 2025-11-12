#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans=0;
struct edge{
	int u,v,w;
}ed[1000015];
bool cmp(edge a, edge b){
	return a.w<b.w;
}
int vst[10005];
int main(){
//Ren5Jie4Di4Ling5%
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a1,a2,a3;
		cin>>ed[i].u>>ed[i].v>>ed[i].w;
	}
	for(int i=n+1;i<=n+k;i++){
		int p;
		cin>>p;
		for(int j=1;j<=n;j++){
			int w1;
			cin>>w1;
			ed[++m].u=j;
			ed[m].v=i;
			ed[m].w=w1;
		}
	}
	sort(ed+1,ed+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i==1){
			vst[ed[i].u]=1;
			vst[ed[i].v]=1;
			ans+=ed[i].w;
		}else{
			bool f=0;
			for(int i=1;i<=n;i++){
				if(vst[i]==0){
					f=1;
					break;
				}
			}
			if(f==0){
				cout<<ans;
				return 0;
			}
			if(vst[ed[i].u]==0 || vst[ed[i].v]==0){
				vst[ed[i].u]=1;
				vst[ed[i].v]=1;
				ans+=ed[i].w;
			}
		}
		
	}
	return 0;
}
