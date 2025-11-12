#include <bits/stdc++.h>
using namespace std;
int a[500005],s[500005];
struct r
{
    int l,r;
}f[500005];
bool cmp(r x,r y)
{
    return x.r<y.r;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=a[i]^s[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        cout<<s[i]<<" ";
    }
    int cur=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if((s[i]^s[j-1])==k)
            {
                cur++;
                f[cur].l=j;
                f[cur].r=i;
            }
        }
    }
    if(cur==0)
    {
        cout<<0;
        return 0;
    }
    sort(f+1,f+cur+1,cmp);
    int last=f[1].r,cnt=1;
    for(int i=2;i<=cur;i++)
    {
        if(f[i].l>last)
        {
            cnt++;
            last=f[i].r;
        }
    }
    cout<<cnt;
    return 0;
}
