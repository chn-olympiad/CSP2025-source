#include<bits/stdc++.h>
using namespace std;
long long int n,m,k,su,summ=1000000000,mm[10005][10005],c[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1,a,b,w;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&w);
		mm[a][b]=mm[b][a]=w;
		su+=w;
	}long long cc,s;
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&cc);
		s=cc;
		for(int j=1,l;j<=n;j++)
		{
			scanf("%lld",l);
			s+=l;
		}
		if(s<summ)summ=s;
	}
	if(summ<m)printf("%lld",summ);
	else printf("%lld",m);
	return 0;
 } 
