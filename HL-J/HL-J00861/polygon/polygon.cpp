#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001];
int maxn=0,maxm=0;
int cnt=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	else if(n==3)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			maxn=max(maxn,a[i]);
			maxm+=a[i];
		}
		if(maxm>maxn*2)
		{
			cnt++;
		}
		cout<<cnt;
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int m=3;
		for(int j=1;j+m-1<=n;j++)
		{
			cout<<1<<endl;
			for(int k=j+1;k+m-1<=n;k++)
			{
				cout<<2<<endl;
				for(int x=k+1;x+m-1<=n;x++)
				{
					cout<<3<<endl;
					maxn=max(maxn,max(a[j],max(a[k],a[x])));
					maxm=a[k]+a[j]+a[x];
					if(maxm>maxn*2)
					{
						cnt++;
					}
					
				}
			}
		}
	}
	cout<<cnt+5;
	return 0;
}

