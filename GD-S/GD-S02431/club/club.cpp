#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
struct node{
	int a,b,c;
}stu[N];
int q;
bool cmp1(node aa,node bb)
{
	return aa.a>bb.a;
}
bool cmp2(node aa,node bb)
{
	return aa.b>bb.b;
}
bool cmp3(node aa,node bb)
{
	return aa.c>bb.c;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&q);
	while(q--)
	{
		int n,maxx=0,ans=0,cnta=0,cntb=0,cntc=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&stu[i].a,&stu[i].b,&stu[i].c);
		}
		sort(stu+1,stu+n+1,cmp1);
		cnta=n/2;
		for(int i=1;i<=n;i++)
		{
			int k=max(stu[i].b,stu[i].c);
			if(i>=n-cnta+1)
			{
				maxx+=k;
				continue;
			}
			if(k>stu[i].a)
			{
				if(stu[i].c>stu[i].b&&cntc<n/2)
				{
					cnta--;
					cntc++;
					maxx+=stu[i].c;
				}
				else if(stu[i].c<=stu[i].b&&cntb<n/2)
				{
					cnta--;
					cntb++;
					maxx+=stu[i].b;
				}
				else maxx+=stu[i].a;
			}
			else maxx+=stu[i].a;
		}
		ans=max(ans,maxx);
		maxx=0;
		sort(stu+1,stu+n+1,cmp2);
		cnta=0;
		cntc=0;
		cntb=n/2;
		for(int i=1;i<=n;i++)
		{
			int k=max(stu[i].a,stu[i].c);
			if(i>=n-cntb+1)
			{
				maxx+=k;
				continue;
			}
			if(k>stu[i].b)
			{
				if(stu[i].c>stu[i].a&&cntc<n/2)
				{
					cntb--;
					cntc++;
					maxx+=stu[i].c;
				}
				else if(stu[i].c<=stu[i].a&&cnta<n/2)
				{
					cntb--;
					cnta++;
					maxx+=stu[i].a;
				}
				else maxx+=stu[i].b;
			}
			else maxx+=stu[i].b;
		}
		ans=max(ans,maxx);
		maxx=0;
		sort(stu+1,stu+n+1,cmp3);
		cntb=0;
		cnta=0;
		cntc=n/2;
		for(int i=1;i<=n;i++)
		{
			int k=max(stu[i].a,stu[i].b);
			if(i>=n-cntc+1)
			{
				maxx+=k;
				continue;
			}
			if(k>stu[i].c)
			{
				if(stu[i].a>stu[i].b&&cnta<n/2)
				{
					cntc--;
					cnta++;
					maxx+=stu[i].a;
				}
				else if(stu[i].a<=stu[i].b&&cntb<n/2)
				{
					cntc--;
					cntb++;
					maxx+=stu[i].b;
				}
				else maxx+=stu[i].c;
			}
			else maxx+=stu[i].c;
		}
		ans=max(ans,maxx);
		cout<<ans<<'\n';
	}
	return 0;
}
