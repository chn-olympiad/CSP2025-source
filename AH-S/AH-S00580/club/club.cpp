#include<bits/stdc++.h>
using namespace std;
int mp[100010][10],a[100010];
int n,ans;
struct node
{
	int x,y,z;
}b[100010];
void dfs(int dep,int a,int b,int c,int rep)
{
	if(dep>n)
	{
		ans=max(ans,rep);
		return ;
	}
		if(a<n/2)
		{
			dfs(dep+1,a+1,b,c,rep+mp[dep][1]);
		}
		if(b<n/2)
		{
			dfs(dep+1,a,b+1,c,rep+mp[dep][2]);
		}
		if(c<n/2)
		{
			dfs(dep+1,a,b,c+1,rep+mp[dep][3]);
		}
}
bool cmp(node l,node k)
{
	return l.z>k.z;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		int cnt=0;
		for(int i=1;i<=n;i++) 
		{
			for(int j=1;j<=3;j++)
			{
				cin>>mp[i][j];	
				if(mp[i][j]==0) cnt++;		
			}
		}			
		if(n<=30)
		{
			dfs(1,0,0,0,0);
			cout<<ans<<endl;			
		}
		else if(cnt==2*n)
		{
			for(int i=1;i<=n;i++)
			{
				a[i]=mp[i][1];
			}
			sort(a+1,a+n+1);
			for(int i=n;i>=n/2;i--)
			{
				ans+=a[i];
			}
			cout<<ans<<endl;
		}
		else
		{
			int d=0,e=0;
			for(int i=1;i<=n;i++)
			{
				b[i].x=mp[i][1];
				b[i].y=mp[i][2];
				b[i].z=abs(mp[i][1]-mp[i][2]);
			}
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n;i++)
			{
				if(b[i].x>b[i].y)
				{
					if(d<n/2)
					{
						d++;
						ans+=b[i].x;
					}
					else
					{
						e++;
						ans+=b[i].y;
					}
				}
				else if(b[i].x<b[i].y)
				{
					if(e<n/2)
					{
						e++;
						ans+=b[i].y;
					}
					else
					{
						d++;
						ans+=b[i].x;
					}
				}
				else
				{
					if(e<n/2&&d<n/2)
					{
						if(e<d)
						{
							e++;
							ans+=b[i].y;
						}
						else
						{
							d++;
							ans+=b[i].x;
						}
					}
					else
					{
						if(e<n/2)
						{
							e++;
							ans+=b[i].y;
						}
						else
						{
							d++;
							ans+=b[i].x;
						}
					}
				}
			}
			cout<<ans<<endl;
		}

	}
	return 0;
}
