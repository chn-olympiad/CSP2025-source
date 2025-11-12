#include<bits/stdc++.h>
using namespace std;
int n,ans,sum,maxx=-1e9;
int a[5010];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(j-i+1>=3)
			{
				for(int k=i;k<=j;k++)
				{
					ans+=a[k];
					maxx=max(maxx,a[k]);
				}
				if(ans>maxx*2) sum++;
				ans=0;
				maxx=-1e9;
				for(int k=i;k<=j;k++)
				{
					cout<<a[k]<<" ";
				}
				cout<<endl;				
			}

		}
	}
	cout<<sum;
	return 0;
}
