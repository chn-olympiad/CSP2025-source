#include <bits/stdc++.h>
using namespace std;
struct px
{
	int o,x;
}o[100005];
int a[100005],b[100005],c[100005],f[100005],k[100005],t,n,s;
bool cmp(px s1,px s2)
{
	if(s1.o!=s2.o)
	{
		return s1.o>s2.o;
	}
	return s1.x<s2.x;
}
void dfs(int x,int l,int m,int r,int v)
{
	if(l*2>n||m*2>n||r*2>n)
	{
		return ;
	}
	if(x>n)
	{
		s=max(s,v);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(i==1)
		{
			dfs(x+1,l+1,m,r,v+a[x]);
		}
		if(i==2)
		{
			dfs(x+1,l,m+1,r,v+b[x]);
		}
		if(i==3)
		{
			dfs(x+1,l,m,r+1,v+c[x]);
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int l,r,m;
		s=0;
		l=0;
		m=0;
		r=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			f[i]=i;
			o[i].o=a[i]-b[i];
			o[i].x=i;
		}
		if(n<=20)
		{
			dfs(0,0,0,0,0);
		}
		else
		{
			sort(o+1,o+n+1,cmp);
			for(int i=1;i<=n;i++)
			{
				if(i>n/2)
				{
					k[o[i].x]=b[o[i].x];
					m++;
					f[o[i].x]=2;
				}
				else
				{
					k[o[i].x]=a[o[i].x];
					l++;
					f[o[i].x]=1;
				}
			}
			for(int i=1;i<=n;i++)
			{
				o[i].o=c[i]-k[i];
			}
			sort(o+1,o+n+1,cmp);
			for(int i=1;i<=n;i++)
			{
				if((c[o[i].x]>k[o[i].x])&&(r<n/2))
				{
					if(f[o[i].x]==1)
					{
						l--;
					}
					else
					{
						m--;
					}
					f[o[i].x]=3;
					k[o[i].x]=c[o[i].x];
					r++;
				}
			}
			for(int i=1;i<=n;i++)
			{
				o[i].o=a[i]-k[i];
			}
			sort(o+1,o+n+1,cmp);
			for(int i=1;i<=n;i++)
			{
				if((a[o[i].x]>k[o[i].x])&&(l<n/2))
				{
					if(f[o[i].x]==2)
					{
						m--;
					}
					else
					{
						r--;
					}
					f[o[i].x]=1;
					k[o[i].x]=a[o[i].x];
					l++;
				}
			}
			for(int i=1;i<=n;i++)
			{
				o[i].o=b[i]-k[i];
			}
			sort(o+1,o+n+1,cmp);
			for(int i=1;i<=n;i++)
			{
				if((b[o[i].x]>k[o[i].x])&&(m<n/2))
				{
					if(f[o[i].x]==1)
					{
						l--;
					}
					else
					{
						r--;
					}
					f[o[i].x]=3;
					k[o[i].x]=b[o[i].x];
					m++;
				}
			}
			for(int i=1;i<=n;i++)
			{
				s=s+k[i];
			}
		}
		cout<<s<<endl;
	}
}
