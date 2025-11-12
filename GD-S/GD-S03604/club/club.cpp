#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200000;
struct node{int a,b,c};
noed a[N];
int vid[N][3];
bool cmp(node a,node b)
{
	if(a.a==b.a)
	{
		if(a.b==b.b)
		{
			return a.c<b.c;
		}
		return a.b<b.b;
	}
	return a.a<b.a;
}
int a1[N],ct1=0,b1[N],ct2=0,c1[N],ct3=0;
signed main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","W",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		metset(a,0,sizeof(a));
		metset(vid,0,sizeof(vid));
		int n;
		cin>>n;
		int ans=0;
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			int l=max(a[i].a,a[i].b,a[i].c);
			if(a[i].a==l)
			{
				a1[++cnt1]=
				vid[i][1]=1;
				vid[i][2]=0;
				vid[i][3]=0;
				cnt1++;
			}
			else if(a[i].b==l)
			{
				vid[i][1]=0;
				vid[i][2]=1;
				vid[i][3]=0;
				cnt2++;
			} 
			else
			{
				vid[i][1]=0;
				vid[i][2]=0;
				vid[i][3]=1;
				cnt3++;
			}
		}
		if(cnt1>int(n/2))
		{
			for(int i=1;i<=n;i++)
			{
				if(vid[i][1]==1)
				{
					if()
				}
			}
		}
	}
}
