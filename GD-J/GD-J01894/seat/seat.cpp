#include<bits/stdc++.h>
using namespace std;
bool o(int x,int y)
{
	if(x>y)return 1;
	else return 0;
}
int n,m,a[101],r,sum,ans;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+(n*m),o);
	for(int i=1;i<=n*m;i+=n)
	{
		sum++;
		if(r<=a[i]&&r>=a[i+n-1])
		{
			for(int j=i;j<=i+n-1;j++)
			{
				if(a[j]==r)
				{
					ans=j;
				}
			}
			ans=ans-(sum-1)*n;
			if(sum%2==0)
			{
				ans=n-ans+1;
			}
			cout<<sum<<" "<<ans;
			return 0;
		}
		
	}
	return 0;
}
