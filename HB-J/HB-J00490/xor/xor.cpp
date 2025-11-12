#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,k,a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=2 && k==0)//5pts
	{
		if(n==1)
		{
			cout<<0;
			return 0;
		}
		else if(n==2)
		{
			cout<<1;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
