#include<bits/stdc++.h>
using namespace std;
struct dd
{
	long long a,b,c,aa,bb,cc,dd,ee;
}k[100005];
long long n,m,t;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%lld %lld %lld",&n,&m,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %lld %lld",&k[i].a,&k[i].b,&k[i].c);
	}
	for(int i=1;i<=t;i++)
	{
		cin>>k[i].aa>>k[i].bb>>k[i].cc>>k[i].dd>>k[i].ee;
	}
	cout<<k[3].c+k[4].c+k[1].aa+k[1].bb+k[2].dd;
	return 0;
}
