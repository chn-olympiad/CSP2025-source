#include<bits/stdc++.h>
#define ll long long//ll  !!!!!!
using namespace std;
const ll N=1e5+10;
ll T,n,m;
ll cnt[4];
struct E{
	ll a,b,c;
	ll id,ma,mi;
}num[N];
int vis[N][4];
bool cmp(E x,E y)
{
	return x.ma>y.ma;
}
int find(int aa,int x)
{
	if(aa==num[x].a)return 1;
	else if(aa==num[x].b)return 2;
	else return 3;
}
void check(int x)
{
	num[x].ma=max(num[x].a,max(num[x].b,num[x].c));
	num[x].mi=min(num[x].a,min(num[x].b,num[x].c));
	num[x].id=find(num[x].ma,x);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		ll ans=0;
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		scanf("%lld",&n);
		m=n/2;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&num[i].a,&num[i].b,&num[i].c);
			check(i);
		}
		sort(num+1,num+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(cnt[num[i].id]<m)
			{
				ans+=num[i].ma;
				cnt[num[i].id]++;
			}
			else
			{
				vis[i][num[i].id]=1;
				int ant,t;
				if(num[i].id==1)ant=max(num[i].b,num[i].c);
				else if(num[i].id==2)ant=max(num[i].a,num[i].c);
				else ant=max(num[i].b,num[i].c);
				t=find(ant,i);
				if(cnt[t]>=m)
				{
					ans+=num[i].mi;
					vis[i][t]=1;
					for(int q=1;q<=3;q++)
					{
						if(vis[i][q]==0)cnt[q]++;
					}
				}
				else
				{
					ans+=ant;
					cnt[t]++;
				}
			}
		}
		printf("%lld",ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
