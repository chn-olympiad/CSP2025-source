#include<bits/stdc++.h>
using namespace std;
unsigned int n,k,a[500000],ans;
void x(unsigned int m)
{
	unsigned int d;
	d=a[m];
	m++;
	while(d!=k&&m<=n)
	{
		d=d xor a[m];
		m++;
	}
	if(m<=n)
	{
		ans++;
		x(m);
	}
	else
		cout<<ans;
}
int main()
{
	unsigned int i;
	cin>>n>>k;
	for(i=0;i<n;i++)
		cin>>a[i];
	x(0);
}
