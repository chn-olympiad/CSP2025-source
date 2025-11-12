#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500050],num=-1,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i = 1;i<=n;++i)
	{
		if(num==-1)
		{
			num=a[i];
			continue;
		}
		else if(num==k)
		{
			ans++;
			num==-1;
			continue;
		}
		else
		{
			num^=a[i];
		}
	} 
	cout<<ans;
	return 0;
}
