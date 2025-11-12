#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5; 
int a[N];
int main()
{
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int r=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int sum=0;
			for(int o=i;o<=j;o++)
			{
				sum=sum^a[o];
			}
			if(sum==k && r<i)
			{
				ans++;
				r=j;
			}
		}
	}
	cout<<ans;
	return 0;
}