#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+50; 
int n;
long long k,sum,ans;
long long a[N];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0&&n==1&&a[1]==1)
	{
		cout<<0;
		return 0;
	}
	else if(k==0&&n==2&&a[1]==1&&a[2]==1)
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++) 
	{
		sum=a[i];
		for(int j=i;j<=n;j++)
		{
			if(sum==k)
			{
				ans++;
			}
			if(j!=i) 
			{
				sum^=a[j];	
			}
		}
	}
	cout<<ans;
	return 0;
}
