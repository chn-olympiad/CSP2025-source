#include<bits/stdc++.h>
using namespace std;
int t,n,k,a[100005][5],al,bl,cl,sn,as[100005];
bool fa,f;
long long  ans,maxx=-INT_MAX;
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int k)
{
	if(k==n+1)
	{
		maxx=max(ans,maxx);
		return ;
	}
	else
	{
		if(al+1<=sn&&a[k][1]!=0)
		{
			ans+=a[k][1];
			k++;
			al++;
			dfs(k);
			k--;
			al--;
			ans-=a[k][1];
		}
		if(bl+1<=sn&&a[k][2]!=0)
		{
			ans+=a[k][2];
			k++;
			bl++;
			dfs(k);
			k--;
			bl--;
			ans-=a[k][2];
		}
		if(cl+1<=sn&&a[k][3]!=0)
		{
			ans+=a[k][3];
			k++;
			cl++;
			dfs(k);
			k--;
			cl--;
			ans-=a[k][3];
		}
		
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	for(int q=1;q<=t;q++)
	{
		cin>>n;
		sn=n/2;fa=0;f=0;ans=0;
		maxx=-INT_MAX;al=0,bl=0,cl=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				a[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				as[i]=a[i][1];
				if(a[i][j]!=0) f=1;
				if(a[i][j]!=0||a[i][j]!=0) fa=1;	
			}
		}
		sort(as+1,as+n+1,cmp);
		if(n<=10)
		{
			dfs(1);
			cout<<maxx<<endl;
		}
		else
		{
			if(fa==0)
			{
				ans=0;
				for(int i=1;i<=sn;i++)
					ans+=as[i];
				cout<<ans<<endl;
				continue;
			}
		}
	}
	return 0;
}

