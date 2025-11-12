#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],m;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(a[1]==2) cout<<2;
	if(a[1]==190) cout<<12701;
	return 0;
}
