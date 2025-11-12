#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
struct z
{
	int a,b,c,s,id;
}x[100005]
bool cmp1(z x,z y)
{
	return x.a>y.a;
}
bool cmp2(z x,z y)
{
	return x.c>y.c;
}
bool cmp3(z x,z y)
{
	return x.b>y.b;
}
void dfs1(int t,int ss,int ar,int br)
{
	 if(ar>n/2||br>n/2) return ;
	 if(t==n+1)
	 {
		 ans=max(ans,ss);
		 return ;
	 }
	 for(int i=t+1;i<=n;i++)
	 {
		 dfs1(i,ss+x[i].a,ar+1,br);
		 dfs1(i,ss+x[i].b,ar,br+1);
	 }
}
void dfs(int t,int ss,int ar,int br,int cr)
{
	 if(ar>n/2||br>n/2||cr>n/2) return ;
	 ans=max(ans,ss);
	 for(int i=t+1;i<=n;i++)
	 {
		 dfs(i,ss+x[i].a,ar+1,br,cr);
		 dfs(i,ss+x[i].b,ar,br+1,cr);
		 dfs(i,ss+x[i].c,ar,br,cr+1);
	 }
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i].a>>x[i].b>>x[i].c;
		}
		bool f=1,ff=1,fff=1;
		for(int i=1;i<=n;i++)
		{
			if(x[i].b!=0||x[i].c!=0)
			{
				f=0;
			}
			if(x[i].b!=0||x[i].a!=0)
			{
				ff=0;
			}
			if(x[i].a!=0||x[i].c!=0)
			{
				fff=0;
			}
		}
		if(f)
		{
			sort(x+1,x+n+1,cmp1);
			for(int i=1;i<=n/2;i++)
			{
				ans+=x[i].a;
			}
			cout<<ans<<'\n';
			continue;
		}
		if(ff==1)
		{
			sort(x+1,x+n+1,cmp2);
			for(int i=1;i<=n/2;i++)
			{
				ans+=x[i].c;
			}
			cout<<ans<<'\n';
			continue;
		}
		if(fff==1)
		{
			sort(x+1,x+n+1,cmp3);
			for(int i=1;i<=n/2;i++)
			{
				ans+=x[i].b;
			}
			cout<<ans<<'\n';
			continue;
		}
		f=1;
		for(int i=1;i<=n;i++)
		{
			if(x[i].c!=0)
			{
				f=0;
				break;
			}
		}
		if(f==1)
		{
			dfs1(0,0,0,0);
			cout<<ans<<'\n';
			continue;
		}
		dfs(0,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
