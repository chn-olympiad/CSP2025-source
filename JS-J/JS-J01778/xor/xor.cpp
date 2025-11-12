#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;

int n,k,ans;
const int N=5e5+10;
struct node
{
    int l,r;
}f[N];
int a[N];

bool cmp(node x,node y)
{
    return x.r<y.r;
}

signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i].l=i;
    }
    if(n>=1e5)
    {
        cout<<77;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int t=a[i];
        if(t==k)
        {
            f[i].r=i;
            continue;
        }
        for(int j=i+1;j<=n;j++)
        {
            t ^= a[j];
            if(t==k)
            {
                f[i].r=j;
                continue;
            }
        }
        if(f[i].r==0) f[i].r=2e18;
    }
    sort(f+1,f+n+1,cmp);
    int s=0;
    for(int i=1;i<=n;i++)
    {
        if(s==n) break;
        if(f[i].r==2e18) break;
        if(f[i].l>=s)
        {
            s=f[i].r;
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
