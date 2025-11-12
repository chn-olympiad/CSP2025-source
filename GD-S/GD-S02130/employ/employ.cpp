#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n;
	int ans=1;
	for(int i=n;i>=1;i--)
	{
		ans*=i%998244353;
		ans%=998244353;
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//u
