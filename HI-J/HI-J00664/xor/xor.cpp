#include<bits/stdc++.h>
using namespace std;
int n,sum;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i*=2)
	sum+=n/i;
	cout<<sum;
	return 0;
}

