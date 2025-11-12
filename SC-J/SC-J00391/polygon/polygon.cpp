#include<bits/stdc++.h>
using namespace std;
int n;
int a[5009];
long long q;
bool vis[5009];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n<3)
	{
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))
		{
			cout<<"1";
		return 0;
		}
		else 
		cout<<"0";
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=1;j++)
		{
			vis[i]=j;	
			int ans=0,sum=0,num=0;
			for(int k=1;k<=i;k++)
			{
				if(vis[k])
				{
					sum++;
					ans=max(ans,a[k]);
					num+=a[k];
					cout<<a[k]<<" ";
				}
			}
			cout<<"\n";
			if(num>ans*2&&sum>=3)
			q++;
			q%=998244353;
		}
	}
	cout<<q*2-1;
	return 0;
} 