#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
ll u,v,w;
ll ok;
struct edge{
	ll u,v,w;
};
edge bian[200009];
edge zz;
ll c[100],l[15][200009];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
//---------------------------//
ll fa[200009],js,hf;
ll size[200009];
ll find(int x){
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return find(fa[x]);
}
void hb(int x,int y){
	ll xx=find(x),yy=find(y);
	if(xx==yy) return;
	size[xx]+=size[yy];
	size[yy]=0;
	
	fa[xx]=yy;
}
//---------------------------//
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		zz={u,v,w};
		bian[i]=zz;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			if(j==0) cin>>c[i],ok=max(c[i],ok);
			else cin>>l[i][j];
		}
	}
	if(k==0){
		for(int i=1;i<=n;i++) fa[i]=i;
		sort(bian+1,bian+1+m,cmp);
		//for(int i=1;i<=js;i++)cout<<u<<" "<<v<<" "<<w<<endl;
		for(int i=1;i<=m;i++){
			zz=bian[i];
			//cout<<zz.u<<" "<<zz.v<<endl;
			if(find(zz.u)==find(zz.v)) continue;
			hb(zz.u,zz.v);
			js++;
			hf+=zz.w;
			if(js==n-1) break;
		}
		cout<<hf;
		return 0;
	}
	else if(ok==0){
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=n;i++) size[i]=1;
		js=m;
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++){
				bian[++js]={n+i,j,l[i][j]};
			}
		sort(bian+1,bian+1+js,cmp);
		for(int i=1;i<=js;i++){
			zz=bian[i];
			//cout<<zz.u<<" "<<zz.v<<endl;
			if(find(zz.u)==find(zz.v)) continue;
			hb(zz.u,zz.v);
			js++;
			hf+=zz.w;
			if(size[zz.u]==n||size[zz.v]==n){
				break;
			}
		}
		cout<<hf;
	}
	return 0;
	}
