#include<bits/stdc++.h>
using namespace std;
long long n,k,a[5000005],sum,b[5000005];
int main()
{
	cin>>n>>k;
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==0)sum++;
			else b[a[i]]++;
		}
		for(int i=1;i<=n;i++)
		{
			sum+=b[a[i]]/2;
			b[a[i]]=0;
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=a[i]&k;
		sum=sum+a[i];
	}
	cout<<sum/k;
	return 0;
}
