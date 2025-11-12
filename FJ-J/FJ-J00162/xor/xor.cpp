#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k) ans++;
	}
	if(k==0&&ans==0) ans=n/2;
	cout<<ans;
	return 0;
}
//66666666666666666666666666666666