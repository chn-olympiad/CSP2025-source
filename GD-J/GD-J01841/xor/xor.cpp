#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,k;
struct node{
	int x,y;
}p[N];
int a[N];
int ans=0;
int ac;
int cnt;
int maxx;
int sum=0;
bool cmp(node l,node r)
{
	return l.y<r.y; 
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			ans=a[i];
			for (int k=i+1;k<=j;k++)
			{
				ans=ans^a[k];
			}
			if (ans==k)
			{
				p[++cnt].x=i;
				p[cnt].y=j;
			}
		}
	}
	sort(p+1,p+1+cnt,cmp);
	for (int i=1;i<=30;i++)
	{
		sum=1;
		ac=p[i].y;
		for (int j=i+1;j<=cnt;j++)
		{
			if (ac<p[j].x)
			{
				sum++;
				ac=p[j].y;
			}
		}
		maxx=max(maxx,sum);
	}
	cout<<maxx<<endl;
	return 0;
}
