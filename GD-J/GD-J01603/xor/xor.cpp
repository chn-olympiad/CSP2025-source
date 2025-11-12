#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[100005],ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
		if(a[i]==1)
			ans++;
	if(k==0)cout<<1;
	else cout<<ans;
	return 0;
}
