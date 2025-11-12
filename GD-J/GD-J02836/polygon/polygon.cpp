#include<bits/stdc++.h>
using namespace std;
int n, a[500005], m;
long long k, s, ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(long long i=3;i<=(1<<n);i++)
	{
		k=s=m=0;
		for(long long t=i,j=0;t;t>>=1,j++)
			if(t&1)
			{
				k++;
				s+=a[j];
				m=max(m,a[j]);
			}
		if(k>2&&s>2*m) ans=(ans+1)% 998244353;
	}
	cout << ans % 998244353;
	return 0;
}
