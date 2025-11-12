#include <bits/stdc++.h>
using namespace std;
bool b2[1000005],b[1000005];
long long n,m,k,sumn,q[1000005],c[15],a[15][1005];
struct ro{
	long long u,v,w;
}r[1000005];
bool cmp(ro x,ro y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
		cin>>r[i].u>>r[i].v>>r[i].w;
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j)
			cin>>a[i][j];
	}
	sort(r+1,r+m+1,cmp);
	int kk=0;
	for(int i=1;i<=m;++i){
		if(!b[r[i].u]&&!b[r[i].v]){
			sumn+=r[i].w;
			q[++kk]=i;
			b[r[i].u]=1;
			b[r[i].v]=1;
			continue;
		}else if(!b[r[i].u]||!b[r[i].v]){
			sumn+=r[i].w;
			b[r[i].u]=1;
			b[r[i].v]=1;
			continue;
		}
		bool tt=0,tt1=0,tt2=0;
		int pp1,pp2;
		for(int j=1;j<=kk;++j){
			if((r[j].u==r[i].u&&r[j].v==r[i].v)||(r[j].v==r[i].u&&r[j].u==r[i].v)){
				tt=1;
				break;
				}
			if(!b2[j]){
				if(r[i].u==r[j].v||r[i].u==r[j].u){
					tt1=1;
					pp1=j;
				}else if(r[i].v==r[j].v||r[i].v==r[j].u){
					tt2=1;
					pp2=j;
				}
			}
		}
		if(tt)  continue;
		if(tt1&&tt2){
			b2[pp1]=1;
			b2[pp2]=1;
			cout<<pp1<<" "<<pp2<<'\n';
			sumn+=r[i].w;
			continue;
		}
	}
	cout<<sumn<<'\n';
	return 0;
}
