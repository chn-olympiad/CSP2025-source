#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int n,m,ans;
struct node{
	int a,b,c;
}a[N];
void dfs(int x,int s,int l1,int l2,int l3)
{
	if(l1>m)return;
	if(l2>m)return;
	if(l3>m)return;
	if(x==n+1)
	{
		ans=max(ans,s);
		return;
	}
	dfs(x+1,s,l1,l2,l3);
	dfs(x+1,s+a[x].a,l1+1,l2,l3);
	dfs(x+1,s+a[x].b,l1,l2+1,l3);
	dfs(x+1,s+a[x].c,l1,l2,l3+1);
}
bool cmp(node x,node y)
{
	return (long long)x.a*x.b*x.c>(long long)y.a*y.b*y.c;
}
bool cmp1(node x,node y)
{
	return x.a>y.a;
}
int get()
{
	int l1=0,l2=0,l3=0;
	int s=0;
	for(int i=n;i>=1;i--)
	{
		if(a[i].a>=max(a[i].b,a[i].c))
		{
			if(l1<m)
			{
				l1++;
				s+=a[i].a;
			}
			else
			{
				if(a[i].b>a[i].c&&l2<m)
				{
					l2++;
					s+=a[i].b;
				}
				else if(l3<m)
				{
					l3++;
					s+=a[i].c;
				}
			}
		}
		else if(a[i].b>=max(a[i].a,a[i].c))
		{
			if(l2<m)
			{
				l2++;
				s+=a[i].b;
			}
			else
			{
				if(a[i].a>a[i].c&&l1<m)
				{
					l1++;
					s+=a[i].a;
				}
				else if(l3<m)
				{
					l3++;
					s+=a[i].c;
				}
			}
		}
		else if(a[i].c>=max(a[i].b,a[i].a))
		{
			if(l3<m)
			{
				l3++;
				s+=a[i].c;
			}
			else
			{
				if(a[i].a>a[i].b&&l1<m)
				{
					l1++;
					s+=a[i].a;
				}
				else if(l2<m)
				{
					l2++;
					s+=a[i].b;
				}
			}
		}
	}
	return s;
}
void solve()
{
	scanf("%d",&n);
	m=n/2;ans=0;
	int f=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		if(a[i].b!=0||a[i].c!=0)f=1;
	}
	if(!f)
	{
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=m;i++)
		{
			ans+=a[i].a;
		}
		cout<<ans<<endl;
		return;
	}
	if(n<=10)
	{
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
		return;
	}
	sort(a+1,a+1+n,cmp);
	ans=max(ans,get());
	cout<<ans<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		solve();
	}
}
