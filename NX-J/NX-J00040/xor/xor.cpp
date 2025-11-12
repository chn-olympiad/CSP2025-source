#include <bits/stdc++.h>
using namespace std;
long long n,k,a[2000005],q[2000005],res;
bool pd(int st,int ed)
{
    for (int i=st;i<=ed;i++)
    {
        if ((q[ed]^q[i-1])==k)
        {
//            cout<<i<<" "<<ed<<" "<<(q[ed]^q[i-1])<<endl;
            return 0;
        }
    }
    return 1;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        q[i]=q[i-1]^a[i];
    }
    int l=1,r=1;
    while (l<=n)
    {
        while (pd(l,r)&&r<=n)
        {
            r++;
        }
        if (r!=n+1)
        {
            res++;
        }
        l=r+1;
        r=l;
    }
    cout<<res;
    return 0;
}
