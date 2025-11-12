#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500050],sum,ans;
bool f;
int main()
{
	freopen("xor5.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;)
	{
		sum=0;
		f=0;
		for(int j=i+1;j<=n;j++)
		{
			sum=sum^a[j];
			if(sum==k)
			{
				ans++;
				i=j;f=1;
				sum=0;
			}
		}
		if(f==0) i++;
	}
	cout<<ans;
	return 0;
}
/*
4 2
2 1 0 3
4 3
2 1 0 3
*/
