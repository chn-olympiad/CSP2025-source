#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],ma,s,t,l;
const int mod=998244353;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=0;i<(1<<n);i++)
	{
		s=0,ma=0,t=0;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
				t++;
				s+=a[j];
				ma=max(ma,a[j]);
			}
		}
		if(t>=3&&s>ma*2) 
		{
			l=(l+1)%mod;
		} 
	}
	cout<<l;
	return 0;
}
