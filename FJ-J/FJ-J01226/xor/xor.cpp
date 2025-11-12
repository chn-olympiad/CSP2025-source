#include<bits/stdc++.h>
#define N 500010
#define ll long long
using namespace std;
int n,k,maxn;
int ff=1,flag=1;
int d[N],v[N];
ll s[N];
queue<int>q;
vector<pair<int,int> >to[N];
void add(int x,int y,int z)
{
	to[x].push_back(make_pair(y,z));
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1,x;i<=n;i++)
	{
		cin>>x;
		if(x!=1)
		{
			ff=0;
		}
		if(x>1)
		{
			flag=0;
		}
		s[i]=x^s[i-1];
	}
	if(ff)
	{
		cout<<(n>>1);
		return 0;
	}
	if(flag)
	{
		int ans=0;
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if((s[i]^s[i-1])==0)
				{
					ans++;
				}
				else if((s[i+1]^s[i-1])==0)
				{
					i++;
					ans++;
				}
				else if((s[i+2]^s[i-1])==0)
				{
					i+=2;
					ans++;
				}
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if((s[i]^s[i-1])==1)
				{
					ans++;
				}
				else if((s[i+1]^s[i-1])==1)
				{
					i++;
					ans++;
				}
				else if((s[i+2]^s[i-1])==1)
				{
					i+=2;
					ans++;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if((s[j]^s[i-1])==k)
			{
				add(i,j,1);
			}
			else
			{
				add(i,j,0);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		memset(v,0,sizeof(v));
		memset(d,0,sizeof(d));
		if((s[i]^s[i-1])==k)
		{
			d[i]=1;
		}
		v[i]=1;
		q.push(i);
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			for(int i=0;i<to[x].size();i++)
			{
				int y=to[x][i].first,z=to[x][i].second;
				if(d[y]<d[x]+z)
				{
					d[y]=d[x]+z;
					if(!v[y])
					{
						q.push(y);
						v[y]=1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,d[i]);
		}
	}
	cout<<maxn;
}
//4 2
//2 1 0 3
//
//4 3
//2 1 0 3
//
//4 0
//2 1 0 3
