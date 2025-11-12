#include<bits/stdc++.h>
using namespace std;
#define N 5010
const int mod=998244353;
int n,z[N],ans;
int main()
{
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>z[i];
	for(int i=0;i<(1<<n);i++)
	{
		int mx=0,sum=0;
		for(int j=0;j<n;j++)
		{
			if((i>>j)&1)
			{
				sum+=z[j+1];
				mx=max(mx,z[j+1]);
			} 
		}
		if(sum>mx*2) ans=(ans+1)%mod;
	}
	cout<<ans;
}
