#include<bits/stdc++.h>
using namespace std;
long long n,k,a,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a==k)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}