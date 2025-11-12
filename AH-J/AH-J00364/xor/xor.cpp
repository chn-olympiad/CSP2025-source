#include<bits/stdc++.h>
using namespace std;
long long a[5000010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,ans=0;
	cin>>n>>k;
	for(long long i=1;i<=n;i++) cin>>a[i];
	long long yhz=0;
	for(long long i=1;i<=n;i++)
	{
		yhz^=a[i];
		if(yhz==k)
		{
			ans++;
			yhz=0;
		}
	}
	cout<<ans;
    return 0;
}
//rp++
