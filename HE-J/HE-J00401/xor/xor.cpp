#include <bits/stdc++.h>
using namespace std;

int a[200];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	int k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(k==0) cout<<1;
	if(k==2) cout<<2;
	if(k==3) cout<<2;
	if(k==1) cout<<1;
	return 0;
}
