#include<bits/stdc++.h>
using namespace std;
long long ssum;
long long n,k;
long long sum[500010];
long long c;
long long f[5000010];
long long cnt;
long long rt;
struct stu
{
	long long l,r,lg;
}a[500010];
bool cmp(stu a,stu b)
{
	if(a.r==b.r)
	{
		return a.lg<b.lg;
	}
	else
	{
		return a.r<b.r;
	}
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>c;
        sum[i]=sum[i-1]^c;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(abs(sum[j]-sum[i-1])==k)
            {
                 cnt++;
                 a[cnt].l=i;
                 a[cnt].r=j; 
                 a[cnt].lg=j-i+1;
            }
        }
    }
    sort(a+1,a+cnt+1,cmp);
    rt=a[1].r;
    for(int i=2;i<=cnt;i++)
    {
		if(rt<a[i].l)
		{
			rt=a[i].r;
			ssum++;
		}
	}
    cout<<ssum+1;
    return 0;
}
