#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
long long n,ans=1; 
int main()
{
	
	freopen("employ.in","r",stdin); 
	freopen("employ.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=Mod;
	}
	cout<<ans;
	return 0;
} 
