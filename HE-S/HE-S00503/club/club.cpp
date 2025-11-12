#include<bits/stdc++.h>
using namespace std;
int t,n;
const int N=1e5+5;
int a[N],b[N],c[N];
bool opa,opb;
int lei;
bool cmp(int x,int y)
{
	return x>y;
}
int cnta,cntb,cntc;
int ans;
void dfs(int k,int ca,int cb,int cc,int sum)
{
	if(ca>n/2||cb>n/2||cc>n/2)
	{
		return ;
	}
	if(k>n)
	{
		ans=max(ans,sum);
		return ;
	}
	dfs(k+1,ca+1,cb,cc,sum+a[k]);
	dfs(k+1,ca,cb+1,cc,sum+b[k]);
	dfs(k+1,ca,cb,cc+1,sum+c[k]);
}
void dfs_2(int k,int ca,int cb,int sum)
{
	if(ca>n/2||cb>n/2)
	{
		return ;
	}
	if(k>n)
	{
		ans=max(ans,sum);
		return ;
	}
	dfs_2(k+1,ca+1,cb,sum+a[k]);
	dfs_2(k+1,ca,cb+1,sum+b[k]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		opa=false;
		opb=false;
		cnta=0,cntb=0,cntc=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=c[i])
			{
				opa=true;
			}
			if(c[i]!=0)
			{
				opb=true;
			}
		}
		if(!opa)
		{
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i];
			}
			cout<<ans<<endl;
		}
		else if(n<=30)
		{
			ans=-1;
			cnta=0,cntb=0,cntc=0;
			//for(int i=1;i<=n;i++)
			{
				dfs(1,0,0,0,0);
			}
			cout<<ans<<endl;
		}
		else if(!opb)
		{
			ans=-1;
			cnta=0,cntb=0;
			//for(int i=1;i<=n;i++)
			{
				dfs_2(1,0,0,0);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
