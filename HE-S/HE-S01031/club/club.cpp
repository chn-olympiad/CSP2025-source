#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[3050005],b[3050050],c[3050050],cha[3000050];
int ans=-INT_MAX,n;
bool f1=1,f2=1;
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int k,int s1,int s2,int s3,int sum)
{
	if(k==n+1)
	{
	//	cout<<s1<<" "<<s2<<" "<<s3<<" "<<sum<<endl;
		ans=max(sum,ans);
		return ;
	}
	if(s1<n/2)
	{
		dfs(k+1,s1+1,s2,s3,sum+a[k]);
	}
	if(s2<n/2)
	{
		dfs(k+1,s1,s2+1,s3,sum+b[k]);
	}
	if(s3<n/2)
	{
		dfs(k+1,s1,s2,s3+1,sum+c[k]);
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int ss=0;
		ans=-INT_MAX;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(c[i]!=0) f2=0;
			if(b[i]!=0) f1=0;
		}
		if(f1)
		{
			sort(a+1,a+n+1);
			for(int i=1;i<=n/2;i++)
			{
				ss+=a[i];
			}
			cout<<ss<<endl;
			return 0;
		}
		else if(f2)
		{
			int ss1=0;
			for(int i=1;i<=n;i++)
			{
				ss1+=a[i];
				cha[i]=b[i]-a[i];
			}
			sort(cha+1,cha+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ss1+=cha[i];
			}
			cout<<ss1<<endl;
			return 0;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
}
