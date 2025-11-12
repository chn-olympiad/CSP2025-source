#include <bits/stdc++.h>
using namespace std;
long long t;
long long n;
long long a[100010];
long long b[100010];
long long c[100010];
long long a2,b2,c2;
long long a3,b3,c3;
long long sh;
long long cnt;
long long cnt2;
long long f;
void dfs(long long w,long long x)
{
	for(long long i=w;i<=n;i++)
	{
		if(a2!=sh&&x==1)
		{
			cnt2+=a[i];
			a2++;
			f=1;
			if(w==n)
			{
				cnt=max(cnt,cnt2);
				cnt2-=a[i];
				return;
			}
			else
			{
				f=0;
				dfs(w+1,1);
				if(f==1)
				{
					a2--;
				}
				
				dfs(w+1,2);
				if(f==1)
				{
					b2--;
				}
				
				dfs(w+1,3);
				if(f==1)
				{
					c2--;
				}
			}
			cnt2-=a[i];
		}
		else if(b2!=sh&&x==2)
		{
			cnt2+=b[i];
			b2++;
			f=1;
			if(w==n)
			{
				cnt=max(cnt,cnt2);
				cnt2-=b[i];
				return;
			}
			else
			{
				f=0;
				dfs(w+1,1);
				if(f==1)
				{
					a2--;
				}
				
				dfs(w+1,2);
				if(f==1)
				{
					b2--;
				}
				
				dfs(w+1,3);
				if(f==1)
				{
					c2--;
				}
			}
			cnt2-=b[i];
		}
		else if(c2!=sh&&x==3)
		{
			cnt2+=c[i];
			c2++;
			f=1;
			if(w==n)
			{
				cnt=max(cnt,cnt2);
				cnt2-=c[i];
				return;
			}
			else
			{
				f=0;
				dfs(w+1,1);
				if(f==1)
				{
					a2--;
				}
				
				dfs(w+1,2);
				if(f==1)
				{
					b2--;
				}
				
				dfs(w+1,3);
				if(f==1)
				{
					c2--;
				}
			}
			cnt2-=c[i];
		}
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		sh=n/2;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		for(long long i=1;i<=3;i++)
		{
			dfs(1,i);
		}
		cout<<cnt<<endl;
		cnt=0;
	}
}
