#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main()
{
	freopen("xor1.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>sum)
		{
			sum=a[i];
		}
	}
	cout<<sum-1;
	return 0;
}
