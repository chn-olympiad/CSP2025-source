#include<bits/stdc++.h>
using namespace std;
struct node
{
    int l,r;
}cnt[500010];
int n,k,a[500010],x,ans,tem=1,m;
bool cmp(node p,node q)
{
    if(p.l==q.l)
    {
        return p.r<q.r;
    }
    return p.l<q.l;
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
    for(int i=1;i<=n;i++)
    {
        x=a[i];
        for(int j=i;j<=n;j++)
        {
            if(x==k)
            {
                cnt[tem].l=i;
                cnt[tem].r=j;
                tem++;
                break;
            }
            x=(x^a[j]);
            cout<<x<<endl;
        }
    }
    sort(cnt+1,cnt+n+1,cmp);
    if(tem==1)
    {
        cout<<0;
        return 0;
    }
    m=cnt[1].r;
    ans=1;
    for(int i=2;i<tem;i++)
    {
        if(cnt[i].l>m)
        {
            ans++;
            m=cnt[i].r;
        }
    }
    cout<<tem<<ans;
    return 0;
}
