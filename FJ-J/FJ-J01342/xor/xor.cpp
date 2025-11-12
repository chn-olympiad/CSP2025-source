#include<bits/stdc++.h>
using namespace std;
const int M=5e6+7;
int a[M];
int vis[M];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,t,ans=0;
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		vis[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int m=a[i];
		if(vis[i]==1)
			continue;
		if(m==t)
		{
			cout<<i<<endl;
			vis[i]=1;
			cout<<m<<endl;
			ans++;
			continue;
		}
		for(int j=i;j<=n;j++)
		{
			for(int k=i+1;k<=j;k++)
			{
				if(vis[k]==0)
					m=m^a[k];
				else
				{
					j=n;
					break;
				}
			}
			if(m==t) 
			{
				for(int k=i;k<=j;k++)
					cout<<k<<' ';
				for(int k=i;k<=j;k++)
					vis[k]=1;
				cout<<endl;
				cout<<m<<endl;
				ans++;
				break;
			}	
			m=a[i];
		}	
	}
	cout<<ans;
    return 0;
}

