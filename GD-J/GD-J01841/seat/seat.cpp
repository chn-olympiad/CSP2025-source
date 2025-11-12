#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int x;
	int id;
}a[1005];
int cnt=0;
int sum=0;
int ans=1; // 加上自己的这个 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cnt++;
			cin>>a[cnt].x;
			if (cnt==1)
			{
				sum=a[cnt].x;
			}
			else
			{
				if (sum<a[cnt].x)
				{
					ans++;
				}
			}
		}
	}
	if (ans==n*m)
	{
		cout<<n<<" "<<m<<endl;
		return 0;
	}
	int k=ans/m;
	ans=ans%m;
	if (ans==0)
	{
		cout<<k<<" ";
		if (k%2==1)
		{
			cout<<"1";
		}
		else
		{
			cout<<n;
		}
		cout<<endl;
	}
	else
	{
		cout<<k+1<<" ";
		k++; 
		if (k%2==0)
		{
			cout<<n-ans+1<<endl;
		}
		else
		{
			cout<<ans<<endl;
		}
	}
	return 0;
}
