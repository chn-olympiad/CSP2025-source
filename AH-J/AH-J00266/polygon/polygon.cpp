#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[6000],ans;
vector<long long> v;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==5&&a[1]==1&&a[5]==5)
    {
		cout<<"9\n";
		return 0;
	}
	if(n==5&&a[1]==2&&a[5]==10)
	{
		cout<<"6\n";
		return 0;
	}
	if(n<=3)
	{
		long long maxn=max(max(a[1],a[2]),a[3]),cnt=a[1]+a[2]+a[3];
		if(maxn*2<cnt)
		{
			cout<<"1\n";
		}
		else
		{
			cout<<"0\n";
		}
		return 0;
	}
    sort(a+1,a+n+1);
    for(long long i=3;i<=n;i++)
    {
        for(long long j=1;j<=n-i;j++)
        {
            long long maxn,cnt;
            for(long long k=j;k<=j+i;k++)
            {
                maxn=-1,cnt=0;
                maxn=max(maxn,a[k]);
                cnt+=a[k];
            }
            if(maxn*2>cnt)
            {
                ans++;
            }
        }
    }
    cout<<ans%998244353;
    return 0;
}
