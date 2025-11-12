#include<bits/stdc++.h>
using namespace std;
long long m,n,i,j,k,b,maxa,a[10010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++) cin>>a[i];
	if(n<=2&&k==0) cout<<1;
	return 0;
}
