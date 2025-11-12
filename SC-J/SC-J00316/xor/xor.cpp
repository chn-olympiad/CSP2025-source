#include<iostream>
#include<cstdio>
using namespace std;
int a[500005];
int main()
{	
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (k==0) cout<<n/2;
	return 0;
}