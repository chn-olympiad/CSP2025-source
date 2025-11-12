#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,cnt,uu,vv,ww,ol,ne,k,fa[10005],cnt2,nedge[10005],eco,cnt3;
ll ans=2e18;
struct edge{
	int u,v,w;
}tu[5000005],ntu[5000005],ctu[5000005];
bool cmp(edge ac,edge wa){
	return ac.w<wa.w;
}
int findfa(int x){
	if(fa[x]!=x)fa[x]=findfa(fa[x]);
	return fa[x];
}
void kruskal(){
	for(int i=1;i<=n;++i)fa[i]=i;
	ll res=0;
	cnt3=0;
	sort(ntu+1,ntu+cnt2+1,cmp);
	for(int i=1;i<=cnt2;++i){
		int fax=findfa(ntu[i].u),fay=findfa(ntu[i].v);
		if(fax!=fay){
			fa[fay]=fax;
			res+=ntu[i].w;
			ctu[++cnt3]=ntu[i];
		}
	}
	if(res+eco<ans){
		for(int i=1;i<=cnt3;++i){
			tu[i]=ctu[i];
		}
		swap(cnt2,cnt);
		ans=res+eco;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>uu>>vv>>ww;
		tu[i].u=uu,tu[i].v=vv,tu[i].w=ww;cnt++;
	}
	for(int j=1;j<=cnt;++j){
		ntu[++cnt2]=tu[j];
	}
	kruskal();
	cnt=cnt3;
	for(int i=1;i<=k;++i){
		cnt2=0;
		cin>>eco;
		for(int j=1;j<=n;++j)cin>>nedge[j];
		for(int j=1;j<=cnt;++j){
			ntu[++cnt2]=tu[j];
		}
		for(int uuu=1;uuu<=n;++uuu){
			for(int vvv=uuu+1;vvv<=n;++vvv){
					ntu[++cnt2].u=uuu,ntu[cnt2].v=vvv,ntu[cnt2].w=nedge[uuu]+nedge[vvv];
			}
		}
		kruskal();
	}
	cout<<ans;
	return 0;
}
