#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[15],a[15][10005],fa[10005],s,xjdl[15][10005],xjxc[15];
struct YDL{
	int u,v,w;
}dl[10005];
struct DL{
	int v,l;
};
struct DK{
	int id,u,v;
};
bool cmp(YDL x,YDL y){
	return x.w<y.w;
}
int F(int x){
	if(fa[x]==x)return x;
	return F(fa[x]);
}
vector<DL>V[10005];
vector<DK>h;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>dl[i].u>>dl[i].v>>dl[i].w;
		V[dl[i].u].push_back(DL{dl[i].v,dl[i].w});
		V[dl[i].v].push_back(DL{dl[i].u,dl[i].w});
	}
	sort(dl+1,dl+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=c[i];j++)cin>>a[i][j],xjdl[i][j]=1;
	}
	for(int i=1;i<=m;i++)if(F(dl[i].u)!=F(dl[i].v))s+=dl[i].w,h.push_back(DK{i,F(dl[i].u),F(dl[i].v)}),fa[F(dl[i].u)]=F(dl[i].v);
	for(auto i:h){
		fa[i.u]=i.u,fa[i.v]=i.v;
		int P1=0,P2=0,xcid=0,fy=dl[i.id].w;
		for(int j=1;j<=k;j++){
			for(int p1=1;p1<=n;p1++){
				for(int p2=p1+1;p2<=n;p2++){
					if(((F(p1)==F(i.u)&&F(p2)==F(i.v))||(F(p2)==F(i.u)&&F(p1)==F(i.v)))&&a[j][p1]*xjdl[j][p1]+a[j][p2]*xjdl[j][p2]+c[j]*xjxc[j]<fy)xcid=j,P1=p1,P2=p2,fy=a[j][p1]*xjdl[j][p1]+a[j][p2]*xjdl[j][p2]+c[j]*xjxc[j];
				}
			}
		}
		fa[F(i.u)]=F(i.v);
		xjxc[xcid]=0,xjdl[xcid][P1]=0,xjdl[xcid][P2]=0;
		s-=dl[i.id].w-fy;
	}
	cout<<s;
	return 0;
}
