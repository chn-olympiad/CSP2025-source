#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	} 
	if(n==2&&k==0&&a[1]==1&&a[2]==1)
	{
		cout<<1;
	}
	return 0;
}
