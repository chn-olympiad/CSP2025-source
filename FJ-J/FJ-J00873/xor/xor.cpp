#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],m,sum;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	m=a[1];
	for(int i=2;i<=n;i++)
	{
		m^=a[i];
		if(m==k)
		{
			sum++;
			m=a[i+1];
			i++;
		}
	}
	cout<<sum;
	return 0;
}
