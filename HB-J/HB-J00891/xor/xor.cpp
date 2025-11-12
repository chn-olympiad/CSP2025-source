#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],ans,b;
int id;
struct node{
    int l,r;
}j[500010];
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
        b=a[i];
        if(b==k)
        {
            id++;
            j[id].l=i;
            j[id].r=i;
            continue;
        }
        for(int h=i+1;h<=n;h++)
        {
            b^=a[h];
            if(b==k)
            {
                id++;
                j[id].l=i;
                j[id].r=h;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int h=i+1;h<=n;h++)
        {
            if(j[h].l<j[i].l || (j[h].l==j[i].l && j[h].r<j[i].r))
            {
                node tt;
                tt.l=j[h].l;
                j[h].l=j[i].l;
                j[i].l=tt.l;
                tt.r=j[h].r;
                j[h].r=j[i].r;
                j[i].r=tt.r;
            }
        }
    }
    ans++;
    int op=j[1].r;
    for(int i=2;i<=id;i++)
    {
        if(j[i].l>op) ans++,op=j[i].r;
    }
    cout<<ans;
    return 0;
}
