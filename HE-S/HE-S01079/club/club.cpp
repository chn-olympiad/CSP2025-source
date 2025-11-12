#include <bits/stdc++.h>
using namespace std;
bool check(int vis[110000],int n)
{
	for (int i=1;i<=n;i++)
	{
		if (vis[i]==0) return false;
	}
	return true;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,a[110000][3],vis[110000]={},vis1[4]={},maxn=0;
		cin>>n;
		if (n<=2)
		{
			int w[3],z[3];
			cin>>w[1]>>w[2]>>w[3];
			cin>>z[1]>>z[2]>>z[3];
			cout<<max(w[1]+z[2],max(w[1]+z[3],max(w[2]+z[3],max(w[2]+z[1],max(w[3]+z[1],w[3]+z[2])))))<<endl;
			continue;
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		int tot=0;
		while (check(vis,n)==false)
		{
			int maxn=-1e9,maxi=0,maxj=0;
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=3;j++)
				{
					if (a[i][j]>maxn)
					{
						maxn=a[i][j];
						maxi=i,maxj=j;
					}
				}
			}
			if (vis1[maxj]<n/2)
			{
				tot+=maxn;
				vis1[maxj]++;
			}
			vis[maxi]=1;
			for (int i=1;i<=3;i++)
			{
				a[maxi][i]=0;
			}
		}
		cout<<tot<<endl;
	}
	return 0;
}
