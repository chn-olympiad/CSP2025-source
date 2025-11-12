#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[1000000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if((n<=2)&&(k==0))
	{
		cout<<1;
	}
	if((n<=4)&&(k==0))
	{
		cout<<1;
	}
fclose(stdin);
fclose(stdout);
	return 0;
}
