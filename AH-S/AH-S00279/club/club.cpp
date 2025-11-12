#include <bits/stdc++.h>
using namespace std;
const int L=1e5+7;
int n;
long long k[5];
long long maxx=0;
struct XB{
	long long w[5];
	long long ma;
	long long oo;
}p[L];
XB p1[L];
bool cmp(XB x,XB y)
{
	return x.oo<y.oo;
}
void work()
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,less<> > Q;
	for (int i=1;i<=3;i++)
	{
		//cout<<k[i]<<endl;
		maxx=max(maxx,k[i]);
		Q.push(make_pair(k[i],i));
	}
	for (int i=1;i<=3;i++)
	{
		pair<int,int> node=Q.top();
		Q.pop();
		int g=node.second;
	//	cout<<g<<endl;
	//cout<<node.first<<endl;
		for (int j=1;j<=n;j++)
		{
			p[j].w[i]=p1[j].w[g];
			if(p1[j].ma==g) p[j].ma=i;
		}
	}	
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		long long ans=0;
		memset(k,0,sizeof(k));
		for (int i=1;i<=n;i++)
		{
			scanf("%lld",&p1[i].w[1]);
			scanf("%lld",&p1[i].w[2]);
			scanf("%lld",&p1[i].w[3]);
			p1[i].ma=max(p1[i].w[1],max(p1[i].w[2],p1[i].w[3]));
			ans+=p1[i].ma;
			if(p1[i].ma==p1[i].w[1]) {p1[i].ma=1;k[1]++;}
			else if(p1[i].ma==p1[i].w[2]) {p1[i].ma=2;k[2]++;}
			else if(p1[i].ma==p1[i].w[3]) {p1[i].ma=3;k[3]++;};
		}
		work();
		for (int i=1;i<=n;i++)
		{
			if(p[i].ma==1)
			{
				p[i].oo=min((p[i].w[1]-p[i].w[2]),(p[i].w[1]-p[i].w[3]));
			}
		}
		sort(p+1,p+n+1,cmp);
		for (int i=1;i<=n;i++)
		{
			//cout<<maxx<<endl;
			if(maxx*2<=n) break;
			if(p[i].ma==1)
			{
				ans-=p[i].oo;
				maxx--;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
