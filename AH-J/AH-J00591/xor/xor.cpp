#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500010],sum;
bool f=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1; i<=n; i++)
	{
		cin>>a[i];
		if(a[i]==1) sum++;
		if(a[i]==0) f=0;
	}
	if(f==1) cout<<n/2;
	else if(f==0 && k==1) cout<<sum;
	else
	{
		sum=0;
		for(int i=1; i<=n; i++)
		{
			if(a[i]==0) sum++;
			else if(a[i+1]==1) sum++,i++;
		}
		cout<<sum;
	}
	return 0;
}