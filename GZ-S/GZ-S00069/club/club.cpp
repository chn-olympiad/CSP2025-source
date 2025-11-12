//GZ-S00069 毕节东辰实验学校 刘顶峰 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
struct man{
	ll a=0,b=0,c=0;
}p[100005];
ll n=0;
ll a=0,b=0,c=0;
ll ans=0; 
void dfs(ll k,ll w)
{
	if(k>n)
	{
		if(ans<=w)
			ans=w;
		return;
	}
	if(a)
	{
		a--;
		w+=p[k].a;
		k++;
		dfs(k,w);
		k--;
		w-=p[k].a;
		a++;
	}
	if(b)
	{
		b--;
		w+=p[k].b;
		k++;
		dfs(k,w);
		k--;
		w-=p[k].b;
		b++;
	}
	if(c)
	{
		c--;
		w+=p[k].c;
		k++;
		dfs(k,w);
		k--;
		w-=p[k].c;
		c++;
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t=0;
	cin>>t;
	while(t--)
	{
		cin>>n;
		a=n/2,b=n/2,c=n/2;
		ans=0;
		for(ll j=1;j<=n;j++)
		{
			cin>>p[j].a>>p[j].b>>p[j].c;
		}
		dfs(1,0);
		printf("%lld\n",ans); 
	}
	return 0;
} 
