#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const LL N=5e3+9,MOD=998244353;
LL n,a[N],ans; 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(LL i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(LL i=1;i<(1<<n);i++)
	{
		LL m=0,s=0,Max=-1;
		for(LL j=0;j<n;j++)
		{
			if((i>>j)&1)
			{
				m++;
				s+=a[j];
				Max=max(Max,a[j]);
			}
		}
		if(m>=3&&s>2*Max) ans=(ans+1)%MOD;
	}
	cout<<ans;
	return 0;
}