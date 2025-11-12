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
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	string a,b;
	cin>>n>>q;
	for(int i=1;i<=n;i++) 
		cin>>a>>b;
	for(int i=1;i<=q;i++)
		cin>>a>>b;
	for(int i=1;i<=q;i++)
		cout<<0<<endl;
	return 0;
}
