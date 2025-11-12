#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,cnt=0;
int a[500005],s[500005];
struct Node
{
    int l,r;
}b[5000005];
bool cmp(Node x,Node y)
{
    if(x.r!=y.r) return x.r<y.r;
    else return x.l>y.l;
}
bool check()
{
    for(int i=1;i<=n;i++)
        if(!(a[i]<=1)) return false;
    return true;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(check())
    {
        if(m==0)
        {
            int lst=1,ans=0;
            for(int i=1;i<=n;i++)
                if(a[i]==0)
                {
                    ans++;
                    ans+=(i-lst)/2;
                    lst=i+1;
                }
            if(a[n]!=0) ans+=(n+1-lst)/2;
            cout<<ans<<"\n";
        }
        else
        {
            int ans=0;
            for(int i=1;i<=n;i++)
                ans+=(a[i]==1);
            cout<<ans<<"\n";
        }
        return 0;
    }
    s[1]=a[1];
    for(int i=2;i<=n;i++)
        s[i]=(s[i-1]^a[i]);
    int cur;
    for(int l=1;l<=n;l++)
        for(int r=l;r<=n;r++)
        {
            cur=s[r]^s[l-1];
            if(cur==m) b[++cnt].l=l,b[cnt].r=r;
        }
    sort(b+1,b+cnt+1,cmp);
    int l=b[1].l,r=b[1].r,ans=1;
    for(int i=2;i<=cnt;i++)
        if(b[i].l>r)
        {
            r=b[i].r;
            ans++;
        }
    cout<<ans<<"\n";
    return 0;
}