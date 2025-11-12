/*#include<bits/stdc++.h>
using namespace std;
int p=0;
//void dfs(int x,int y,int z)
//{
//	p++;
//	if(p>=5)
//	{
//		sum=max(sum,)
//	}
//}
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int n,t,a[100001][100001],b[100001],c[100001],sum=0,ans;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			for(int w=1;w<=3;w++)
				cin>>a[j][w];
		}
		//dfs(a[1][1],a[1][2],a[1][3]);
		cout<<sum<<" ";
	}
	return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
int p=0;
//void dfs(int x,int y,int z)
//{
//	p++;
//	if(p>=5)
//	{
//		sum=max(sum,)
//	}
//}
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int n,t,a[100001][100001],b[100001],c[100001],sum=0,ans;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			for(int w=1;w<=3;w++)
				cin>>a[j][w];
		}
		//dfs(a[1][1],a[1][2],a[1][3]);
		cout<<sum<<" ";
	}
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a[1000],ans=0,k,jjy;
	long long sum=1;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=0)
			ans++;
	}
	sort(a,a+n+2);
	k=ans-m;
	for(int i=1;i<=n;i++)
		if(a[i]<=k)
		{
			jjy=i;
			if(a[i]>k)
				break;
		}
	//cout<<jjy;
	/*for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	//cout<<ans;
	*/
	if(ans>=m)
	{
		for(int i=1;i<=m;i++)
		{
			sum*=ans;
			ans--;
		}
		cout<<sum%998244353;
		return 0;
	}
	/*if(ans>m)
	{
		for(int i=1;i<=ans;i++)
		{
			sum*=m;
			m--;
		}
	}*
	*/
	return 0;
}
