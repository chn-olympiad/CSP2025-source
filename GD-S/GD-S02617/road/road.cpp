#include<bits/stdc++.h> 
using namespace std;
const int K=15,N=10005,M=1000005;
int n,m,k,an,s;
struct road
{
	int a,b,c;
}mm[M],al[M+N*K],now;
int nn[K][N],nm[K],no;
int da[N+K];
bool cmp(road A,road B)
{
	return A.c<B.c;
}
int f(int j)
{
	return (da[j]==j?j:(da[j]=f(da[j])));
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>mm[i].a>>mm[i].b>>mm[i].c;
		an+=mm[i].c;
	}
	for(int i=1;i<=n;i++)
	{
		da[i]=i;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>nn[i][0];
		an+=nn[i][0];
		for(int j=1;j<=n;j++)
		{
			cin>>nn[i][j];
			an+=nn[i][j];
		}
	}
	sort(mm+1,mm+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(f(mm[i].a)!=f(mm[i].b))
		{
			da[f(mm[i].a)]=f(mm[i].b);
			no+=mm[i].c;
		}
	}
	cout<<no;
	return 0;
 } 
