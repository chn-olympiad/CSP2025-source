#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>

using namespace std;

const int N=5e3,mod=998244353;

int n;
int a[N+1];

int ans;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
	
	cin>>n;
	for(int i=1;n-i-1>=1;i++)
	{
		ans=(ans+(1ll*(n-1-i)*i)%mod)%mod;
	}
	
	cout<<ans;
	
	return 0;
}

