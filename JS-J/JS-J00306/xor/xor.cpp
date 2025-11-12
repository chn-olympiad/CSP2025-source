#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k;
int a[N];
int h[N];
struct line
{
    int l;
    int r;
};
stack<line> p;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    int f1=1,f2=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>1)f1=0,f2=0;
        if(a[i]!=1) f1=0;
    }
    if(k==0&&f1)
    {
        cout<<n/2;
        return 0;
    }
    if(k<=1&&f2)
    {
        if(k==0)
        {
            int ans=(a[1]==0?1:0);
            for(int i=2;i<=n;i++)
            {
                if(a[i]==0) ans++;
                else if(a[i]==a[i-1]&&a[i]==1) ans++,a[i]=0;
            }
            cout<<ans;
            return 0;
        }
        else
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1) ans++;
            }
            cout<<ans;
            return 0;
        }
    }

    h[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        h[i]=h[i-1]^a[i];
    }
    for(int lft=1;lft<=n;lft++)
    {
        for(int rit=lft;rit<=n;rit++)
        {
            if(h[rit]^h[lft-1]==k)
            {
                line x ;
                x.l=lft;x.r=rit;
                if(p.empty()) p.push(x);
                else
                {
                    while(!(p.empty())&&x.l>p.top().l&&x.r<p.top().r) p.pop();
                    if(!(p.top().l<x.l&&p.top().r<x.r)) p.push(x);
                }
                break;
            }

        }
    }
    int ans=0;
    while(!p.empty()) 
    {
        ans++;
        p.pop();
    }
    cout<<ans;
    return 0;
}