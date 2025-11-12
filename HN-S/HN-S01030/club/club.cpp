#include<bits/stdc++.h>
using namespace std;
int a[5][1000005],n,ans;
#define fi first
#define se second
int m[1000005],b[1000005],s[1000005],vis[1000005];
pair<int,int>v1[1000005],v2[1000005],v3[1000005];
void dfs(int step,int sum,int c1,int c2,int c3)
{
	if(c1>n/2||c2>n/2||c3>n/2)
	{
		return ;
	}
	if(step>n)
	{
		ans=max(ans,sum);
	}
	dfs(step+1,sum+a[1][step],c1+1,c2,c3);
	dfs(step+1,sum+a[2][step],c1,c2+1,c3);
	dfs(step+1,sum+a[3][step],c1,c2,c3+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int f=0; 
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[2][i]!=0)
			{
				f=1;
			}
		}
		if(n<=30)
		{
			dfs(1,0,0,0,0);
			cout<<ans;
		}
		else if(f==0)
		{
			sort(a[1]+1,a[1]+n+1);
			reverse(a[1]+1,a[1]+n+1);
			int ans=0;
			for(int i=1;i<=n/2;i++)
			{	
				ans+=a[1][i];
			}
			cout<<ans<<endl;
		}
		else
		{
			int n,cnt1=0,cnt2=0,cnt3=0;
			cin>>n;
			for(int i=1;i<=n;i++)
			{
				int a1,a2,a3;
				cin>>a1>>a2>>a3;
				v1[++cnt1]={a1,i};
				v2[++cnt2]={a2,i};
				v3[++cnt3]={a3,i};
				b[i]=max({a1,a2,a3});
				s[i]=min({a1,a2,a3});
				if(a1>=a2&&a1<=a3)
				{
					m[i]=a1;
				}
				else if(a2>=a3&&a2<=a1)
				{
					m[i]=a2;
				}
				else
				{
					m[i]=a3;
				}
				vis[i]=0;
			}	
			sort(v1+1,v1+n+1);
			sort(v2+1,v2+n+1);
			sort(v3+1,v3+n+1);
			reverse(v1+1,v1+n+1);
			reverse(v2+1,v2+n+1);
			reverse(v3+1,v3+n+1);
			cnt1=cnt2=cnt3=1;
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(v1[i].fi==b[v1[i].se]&&!vis[v1[i].se])
				{
					if(cnt1<=n/2)
					{
						cnt1++;
						ans+=v1[i].fi;
						vis[v1[i].se]=1;
					}
				}
				if(v2[i].fi==b[v2[i].se]&&!vis[v2[i].se])
				{
					if(cnt2<=n/2)
					{
						cnt2++;
						ans+=v2[i].fi;
						vis[v2[i].se]=1;
					}
				}
				if(v3[i].fi==b[v3[i].se]&&!vis[v3[i].se])
				{
					if(cnt3<=n/2)
					{	
						cnt3++;
						ans+=v3[i].fi;
						vis[v3[i].se]=1;
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(v1[i].fi==m[v1[i].se]&&!vis[v1[i].se])
				{
					if(cnt1<=n/2)
					{
						cnt1++;
						ans+=v1[i].fi;
						vis[v1[i].se]=1;
					}
				}
				if(v2[i].fi==m[v2[i].se]&&!vis[v2[i].se])
				{
					if(cnt2<=n/2)
					{
						cnt2++;
						ans+=v2[i].fi;
						vis[v2[i].se]=1;
					}
				}
				if(v3[i].fi==m[v3[i].se]&&!vis[v3[i].se])
				{
					if(cnt3<=n/2)
					{	
						cnt3++;
						ans+=v3[i].fi;
						vis[v3[i].se]=1;
					}
				}
			}
				for(int i=1;i<=n;i++)
			{
				if(v1[i].fi==s[v1[i].se]&&!vis[v1[i].se])
				{
					if(cnt1<=n/2)
					{
						cnt1++;
						ans+=v1[i].fi;
						vis[v1[i].se]=1;
					}
				}
				if(v2[i].fi==s[v2[i].se]&&!vis[v2[i].se])
				{
					if(cnt2<=n/2)
					{
						cnt2++;
						ans+=v2[i].fi;
						vis[v2[i].se]=1;
					}
				}
				if(v3[i].fi==s[v3[i].se]&&!vis[v3[i].se])
				{
					if(cnt3<=n/2)
					{	
						cnt3++;
						ans+=v3[i].fi;
						vis[v3[i].se]=1;
					}
				}
			}
			cout<<ans<<endl; 
		} 
	}
	return 0;
 }  
