#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
struct node
{
	int a[5];
}s[N];
int cnt=-1;
int t,acnt=0,bcnt=0,ccnt=0;
int n;
void dfs(int ans,int d)
{
	cnt=max(ans,cnt);
	if(d>n)
	{
		return;
	}
	int na=s[d].a[1],nb=s[d].a[2],nc=s[d].a[3];
	//sort(s[d].a+1,s[d].a+4);
	if(acnt+1 > n/2)
	{
		;
	}
	else
	{
		ans+=na;
		acnt++;
		dfs(ans,d+1);
		acnt--;
		ans-=na;
	}
	if(bcnt+1 > n/2)
	{
		;
	}
	else
	{
		ans += nb;
		bcnt++;
		dfs(ans,d+1);
		bcnt--;
		ans -= nb;
	}
	if(ccnt+1 > n/2)
	{
		return;
	}
	else
	{
		ans+=nc;
		ccnt++;
		dfs(ans,d+1);
		ans=ans-nc;
		ccnt--;
	}
}
signed main()
{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		n=0;
		scanf("%lld",&n);
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&s[i].a[1],&s[i].a[2],&s[i].a[3]);
		}
		dfs(0,1);
		printf("%lld\n",cnt);
		acnt=0;
		bcnt=0;
		ccnt=0;
	}
}
