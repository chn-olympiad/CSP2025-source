#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2*1e5+5;
int n,k;
int a[N],ans,cnt,last;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]==1)
		{
			cnt++;
			last=i;
		}
	}
	if(k==0)
	{
		if(cnt%2==0)
		{
			cout<<n;
			return 0;
		}
		else
		{
			if(last>(n+1)/2)
			{
				cout<<last-1;
				return 0;
			}
			else
			{
				cout<<n-last;
				return 0;
			}
		}
	}
	else if(k==1)
	{
		if(cnt%2!=0)
		{
			cout<<n;
			return 0;
		}
		else
		{
			if(last>(n+1)/2)
			{
				cout<<last-1;
				return 0;
			}
			else
			{
				cout<<n-last;
				return 0;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
001
000
001
011
010
*/
// 10 0
//0 1 0 0 1 0 1 1 0 1
