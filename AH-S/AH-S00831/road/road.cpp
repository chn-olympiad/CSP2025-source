#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int n,m,k,fa[10086],pa[10086];
long long ans=0;
struct edg{
	int from,to;
	long long w;
}e[N];
bool cmp(edg a,edg b)
{
	return a.w<b.w;
}
int main()
{
   freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
   cin>>n>>m>>k;
   memset(fa,0,sizeof(fa));
   for(int i=1;i<=m;i++)
   {
	  cin>>e[i].from>>e[i].to>>e[i].w; 
   }
   sort(e+1,e+1+m,cmp);
   int cnt=1,f,t;
   for(int i=1;i<=m;i++)
   {
	   f=e[i].from;
	   t=e[i].to;
	   if(fa[f]==0&&fa[t]==0)
	   {
		   fa[f]=cnt;
		   fa[t]=cnt;
		   ans+=e[i].w;
		   pa[cnt]=2;
		   cnt++;
		}
		else if(fa[f]==0&&fa[t]!=0)
		{
			fa[f]=fa[t];
			ans+=e[i].w;
			pa[fa[t]]++;
		}
		else if(fa[t]==0&&fa[f]!=0)
		{
			fa[t]=fa[f];
			ans+=e[i].w;
			pa[fa[f]]++;
		}
		else
		{
			if(fa[f]<fa[t])
			{
				fa[t]=fa[f];
				ans+=e[i].w;
				pa[fa[f]]+=pa[fa[t]];
			}
			if(fa[f]>fa[t])
			{
				fa[f]=fa[t];
				ans+=e[i].w;
				pa[fa[t]]+=pa[fa[f]];
			}
		}
		if(pa[1]==n){cout<<ans;break;}
   }
   return 0;
}
