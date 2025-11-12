#include<bits\stdc++.h>
using namespace std;
int n,m,k;
int a[5021][5021];
bool fa=1;
bool v[11];
bool vs[5021];
long long ans;
long long s;
bool fb=1;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i(1); i<=m; i++)
	{
		int aaa,bbb,www;
		cin>>aaa>>bbb>>www;
		a[aaa][bbb]=a[bbb][aaa]=www;
		s+=www;
	}
	for(int i(1); i<=k; i++)
	{
		int www;
		cin>>www;
		if(www!=0)
		{
			fa=0;
		}
		a[n+k][n+k]=www;
		for(int j(1); j<=n; j++)
		{
			int ccc;
			cin>>ccc;
			a[n+k][j]=a[j][n+k]=ccc;
			if(ccc>0)
				fb=0;
		}
	}
	if(fb==1)
	{
		cout<<0;
		return 0;
	}
	if(m==n-1)
	{
		if(k==0)
		{
			cout<<s;
			return 0;
		}
		if(fa==1)
		{
			int sv=n-1;
			int sf=0;
			int dd;
			for(int i(1);i<=n;i++)
			{
				sf=0;
				for(int j(1);j<=n;j++)
				{
					if(a[i][j]>0)
						sf++;
				}
				if(sf==1)
				{
					dd=i;
					break;
				}
			}
			vs[dd]=1;
			while(sv--)
			{
				int i;
				for(i=1;i<=n;i++)
				{
					if(a[dd][i]==1&&vs[i]==0)
					{
						for(int j(1);j<=k;j++)
						{
							a[dd][i]=min(a[dd][i],a[dd][n+j]+a[n+j][i]);
						}
					}
				}
				ans+=a[dd][i];
				dd=i;
				vs[i]=1;
				sv--;
			}
			cout<<ans;
		}
		return 0;
	}
	if(k==0)
	{
		for(int o(1); o<=n; o++)
		{
			for(int i(1); i<=n; i++)
			{
				for(int j(1); j<=n; j++)
				{
					if(a[i][j]>=1)
					{
						if(a[i][k]+a[k][j]<a[i][j]&&a[i][k]>0&&a[k][j]>0)
						{
							a[i][j]=a[i][k]+a[k][j];
						}
					}
				}
			}
		}
		cout<<a[1][n];
		return 0;
	}
	cout<<s-n;
	return 0;
}
