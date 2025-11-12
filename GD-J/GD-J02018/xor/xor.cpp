#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	long long summ=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)summ++;
	}
	cout<<summ;
	return 0;
}

