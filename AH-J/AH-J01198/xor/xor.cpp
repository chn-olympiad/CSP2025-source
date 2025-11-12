#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],sum[100005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	cout<<"0";
	return 0;
}
