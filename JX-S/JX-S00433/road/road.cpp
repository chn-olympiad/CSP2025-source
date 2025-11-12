#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[105000];
int get(int x){
if(x==fa[x])return x;
return fa[x]=get(fa[x]);
}
void merge(int x,int y){
fa[x]=get(fa[y]);
}
struct op{
	int u,v,w;
};
bool cmp(op x,op y){
	return x.w<y.w;
}
op side[1100010];
int main()
{
freopen("road.in", "r", stdin);
freopen("road.out", "w", stdout);
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
cin>>n>>m>>k;
int sc[k+10],con[k+10][n+10];
for(int i=0;i<m;i++)
	cin>>side[i].u>>side[i].v>>side[i].w;
for(int i=0;i<k;i++)
{
	cin>>sc[i];
	for(int j=1;j<=n;j++)
	cin>>con[i][j];
}
long long ansn=2147483644;
for(int g=0;g<=((1<<k)-1);g++){
	int x=0,f=1,dm=0,dn=0;
	long long ans=0;
	for(int r=0;r<k;r++){
		if((g>>r)%2==1){
			if(sc[r]>=ansn){f=0;break;}
			else {
				ans+=sc[r];
				x++;
				for(int i=1;i<=n;i++){
					op hd;
					hd.u=n+x;
					hd.v=i;
					hd.w=con[r][i];
					side[m+i+n*(x-1)-1]=hd;
				}
			}
		}
	}
	dn=x;
	dm=x*10;
	n=n+dn,m=m+dm;
	if(f==0)continue;
sort(side,side+m,cmp);
for(int i=1;i<=n;i++)fa[i]=i;
for(int i=0;i<m;i++)
{
	int u=side[i].u,v=side[i].v,w=side[i].w;
	if(get(u)==get(v))continue;
	else {
		merge(get(u),get(v));
		ans+=w;
	}
}
ansn=min(ans,ansn);
n-=dn;
m-=dm;
}
cout<<ansn<<'\n';

return 0;
}
