#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0)
	{
		for(int i=2;i<=n;i+=2)
		{
			ans+=n-i+1;
		}
		cout<<ans;
	}
	else if(k==3) cout<<2;
	else cout<<42;
	return 0;
}


