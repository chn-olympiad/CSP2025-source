#include<bits/stdc++.h>
using namespace std;
struct _
{
	int a,b,c,fst,sec,sta1,sta2;
}p[100005];
bool cmp(int x,int y)
{
	return x>y;
}
int n,cnt[4],lim,ans,t,sta[100005],lis[100005],len;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cnt[1] = cnt[2] = cnt[3] = ans = len = 0;
		cin>>n;lim = n>>1;
		for(int i = 1;i<=n;i++)
		{
			cin>>p[i].a>>p[i].b>>p[i].c;
			p[i].fst = max(p[i].a,max(p[i].b,p[i].c));
			if(p[i].fst== p[i].a)p[i].sec = max(p[i].b,p[i].c),p[i].sta1 = 1,p[i].sta2 = (p[i].sec == p[i].b?2:3);
			if(p[i].fst== p[i].b)p[i].sec = max(p[i].a,p[i].c),p[i].sta1 = 2,p[i].sta2 = (p[i].sec == p[i].a?1:3);
			if(p[i].fst== p[i].c)p[i].sec = max(p[i].a,p[i].b),p[i].sta1 = 3,p[i].sta2 = (p[i].sec == p[i].b?2:1);
		}
		for(int i = 1;i<=n;i++)
		{
			cnt[p[i].sta1]++;
		}
		if(cnt[1]>lim)
		{
			for(int i = 1;i<=n;i++)
			{
				if(p[i].sta1 == 1)lis[++len] = p[i].fst-p[i].sec,ans+=p[i].sec;
				else ans+=p[i].fst;
			}
			sort(lis+1,lis+len+1,cmp);
			for(int i = 1;i<=lim;i++)ans+=lis[i];
		}
		else if(cnt[2]>lim)
		{
			for(int i = 1;i<=n;i++)
			{
				if(p[i].sta1 == 2)lis[++len] = p[i].fst-p[i].sec,ans+=p[i].sec;
				else ans+=p[i].fst;
			}
			sort(lis+1,lis+len+1,cmp);
			for(int i = 1;i<=lim;i++)ans+=lis[i];
		}
		else if(cnt[3]>lim)
		{
			for(int i = 1;i<=n;i++)
			{
				if(p[i].sta1 == 3)lis[++len] = p[i].fst-p[i].sec,ans+=p[i].sec;
				else ans+=p[i].fst;
			}
			sort(lis+1,lis+len+1,cmp);
			for(int i = 1;i<=lim;i++)ans+=lis[i];
		}
		else
		{
			for(int i = 1;i<=n;i++)ans+=p[i].fst;
		}
		cout<<ans<<'\n';
	}
}