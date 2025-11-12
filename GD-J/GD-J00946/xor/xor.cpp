#include <bits/stdc++.h>
using namespace std;
long long n,k;
unordered_map<long long,int> um; 
long long a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long nvis=0;
	int ans=0;
	um.emplace(nvis,1);
	for(int i=1;i<=n;i++)
	{
		nvis^=a[i];
		if(um.find(nvis^k)!=um.end()||a[i]==k)
		{
			ans++;
			um.clear();
			um.emplace(nvis,1);
		}
		else
		{
			um.emplace(nvis,1);
		}
	}
	cout<<ans;
}
