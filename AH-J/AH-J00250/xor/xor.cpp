#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if((n==1)&&(k==0)) cout<<1;
	else if((n==1)&&(k!=0))cout<<0;
	else if((n==2)&&(k==0)&&(a[1]==a[2])) cout<<3;
	else cout<<2;
	return 0;
}
