#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+25;
const int M=1e6+5;
int n,m,p,k,f[N],t[15][N],ans,ppp,bns,cns;
struct stu{
	int u,v,w,d;
}a[M],b[M];
bool cmp1(stu a,stu b){return a.w<b.w;}
bool cmp2(stu a,stu b){
	if(a.d!=b.d)return a.d>b.d;
	else return a.w<b.w;
}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void init(){
	for(int i=1;i<=n+10;i++)
		f[i]=i;
}
bool merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return false;
	f[x]=y;
	return true;
}
int js(int mm){
	init();
	for(int i=1;i<=mm;i++)
		b[i]=a[i];
	bns=0;
	sort(b+1,b+1+mm,cmp1);
	for(int i=1;i<=mm;i++)
		if(merge(b[i].u,b[i].v))bns+=b[i].w;
	return bns;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	init();
	p=n;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+1+m,cmp1);
	for(int i=1;i<=m;i++)
	{
		if(merge(a[i].u,a[i].v)){
			ans+=a[i].w;
			a[i].d=1;
		}
	}
	sort(a+1,a+1+m,cmp2);
	for(int i=1;i<=k;i++)
	{
		cin>>t[i][0];
		for(int j=1;j<=n;j++)
			cin>>t[i][j];
	}
	int cnt=0;
	for(int i=1;i<(1<<k);i++)
	{
		cnt=n-1;
		ppp=0;
		for(int j=1;j<=k;j++)
		{
			if(i&(1<<(j-1))){
				ppp+=t[j][0];
				for(int w=1;w<=n;w++)
				{
					cnt++;
					a[cnt].u=j+n;
					a[cnt].v=w;
					a[cnt].w=t[j][w];
				}
			}
		}
		ans=min(ans,js(cnt)+ppp);
	}
	cout<<ans<<"\n";
	return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
