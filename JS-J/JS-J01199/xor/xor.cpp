#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],sum;
struct A
{

    long long l,r;
}s[500005];
bool cmp(A x,A y)
{
    if(x.r==y.r)
    {
        return x.l>y.l;
    }
    return x.r<y.r;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    int now=0,cnt=0;
    for(int l=1;l<=n;l++)
    {
        now=0;
        for(int r=l;r<=n;r++)
        {
            now^=a[r];
            if(now==k)
            {
                //cout<<l<<" "<<r<<endl;
                s[++cnt].l=l;
                s[cnt].r=r;
                break;
            }
        }
    }
    sort(s+1,s+cnt+1,cmp);
    long long h=s[1].r;
    sum++;
    for(int i=2;i<=cnt;i++)
    {
        if(s[i].l>h)
        {
            sum++;
            h=s[i].r;
        }
    }
    cout<<sum;
    return 0;
}
