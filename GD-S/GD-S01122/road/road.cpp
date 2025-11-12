//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
struct rr{
	int x,y,w;
}r[1100000];
int kl[400],pd,ml;
int u[12][20100];
int cmp(rr aa,rr bb){
	return aa.w<bb.w;
}
int fa[20100];
int hz(int tz){
	if(fa[tz]==tz)return tz;
	return fa[tz]=hz(fa[tz]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>r[i].x>>r[i].y>>r[i].w;
	ml=m;
	for(int i=1;i<=k;i++){
		cin>>kl[i];
		if(kl[i]!=0){
			pd=1;
		}
		for(int o=1;o<=n;o++)cin>>u[i][o];
		for(int o=1;o<=n-1;o++){
			for(int p=o+1;p<=n;p++){
				ml++;
				r[ml].x=o;
				r[ml].y=p;
				r[ml].w=u[i][o]+u[i][p];
			}
		}
	}
	if(pd==0){
		long long ans=0;
		sort(r+1,r+ml+1,cmp);
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=ml;i++){
			int al=r[i].x,bl=r[i].y,cl=r[i].w;
//			cout<<al<<' '<<bl<<' '<<cl<<endl;
			if(hz(al)!=hz(bl)){
				ans=ans+cl;
				fa[hz(bl)]=hz(al);
				
			}
		}
		cout<<ans;
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4
*/
