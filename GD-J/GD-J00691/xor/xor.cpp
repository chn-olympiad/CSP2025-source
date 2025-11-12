#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,c=0;i<=n;i++)
	{
		c=c xor a[i];
		if(c==k)ans++,c=0;
	}
	cout<<ans;
	return 0;
}
