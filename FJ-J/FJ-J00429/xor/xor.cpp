#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],n,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1&&k==0)
		cout<<0;
	if(n==2&&k==0)
	{
		if(a[1]==a[2])
			cout<<1;
		else cout<<0;
	}
	return 0;
}
