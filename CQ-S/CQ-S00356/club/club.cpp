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
//A

#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t,a[100001],b[100001],c[100001];
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
			cin>>a[j]>>b[j]>>c[j];
		int sum=0;
		sort(a,a+n+1);
		for(int j=n;j>n/2;j--)
			sum+=a[j];
		cout<<sum<<endl;
	}
	return 0;
}//*/
