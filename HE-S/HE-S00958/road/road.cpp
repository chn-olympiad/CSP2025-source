#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long sm=le5,ct=le5;
struct cs{
	int u;
	int fy[1234],lsbl=0;
	int *p[1234];
}w[100000001];
struct xc{
	int a,lsbl=0;
	int fy[1234];
	int *dl[1234];
}c[100000010];
int hs(cs &fy1,cs df1,cs bl1,int bl){
	bl=0;
	while(bl<=bl1){
		if(df1!=1){
			sm+=&fy1;
			sm=min(sm,hs(sm,*fy2,bl1,bl++));
		}
	}
	return sm;
}
int hs2(cs &fy1,cs df1,cs csbl1,int csbl,int xcbl,xc &fy,xc df,xc xcbl1){
	csbl=0;
	xcbl=0;
	while(csbl<=csbl1){
		if(df1!=1){
			sm+=&fy1;
			sm=min(sm,hs(sm,*fy2,bl1,bl++));
		}
	}
	while(xcbl<=xcbl1){
		if(df!=1){
			sm+=&fy;
			sm=min(sm,hs(sm,*fy2,bl1,bl++));
		}
	}
	return sm;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		w[a].p[w[i].lsbl]->w[b].fy[c];
		w[a].lsbl++;
		w[b].p[w[i].lsbl]->w[a].fy[c];
		w[b].lsbl++;
	}
	for(int i=1;i<=k;i++){
		int a,b;
		cin>>a;
		for(int j=1;j<=n;j++){
			cin>>b;
			c[a].dl[c[j].lsbl]->w[b].fy[c];
			c[a].lsbl++;
			w[a].p[w[j].lsbl]->c[b].fy[c];
			w[a].lsbl++;
		}
		sm=min(hs2(w[1].p,w[1].u,w[1].lsbl,0,int 0,xc c[1].dl,c[1].a,c[1].lsbl));
	}
	
	cout<<min(sm,hs(w[1].p,w[1].u,w[1].lsbl,0));
	return 0;
}
