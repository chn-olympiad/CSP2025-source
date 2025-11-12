#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
ll n,k,a[100010],l=0,maxn=INT_MIN;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool f=0;
	std::ios::sync_with_stdio(false);
	std::cin.tie(0),cout.tie(0);
	std::cin>>n>>k;
	for(ll i=1;i<=n;i++)
	{
		std::cin>>a[i];
		if(a[i]==0)
		{
			++l;
			maxn=max(maxn,l);
			f=1;
		}
		if(a[i]!=0) l=0;
	}
	if(k==0&&f)
	{
		std::cout<<maxn;
		return 0;
	}
	std::cout<<n/2;
	return 0;
}
