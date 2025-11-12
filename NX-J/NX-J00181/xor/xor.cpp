#include<bits/stdc++.h>
using namespace std;
int n,k,a[500000],c,cnt,lr;
struct x
{
    int l,r;
};
x y[500000];
bool b(x o,x g)
{
    return o.l<g.l;
}
int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    while(1)
    {
        for(int i=1; i<=n; i++)
        {
A:
            for(int j=n; j>=i; j--)
            {
                int z;
                for(int q=i; q<=j; q++)
                {
                    z^=q;
                    if(z==k)
                    {
                        y[c].l=i;
                        y[c].r=q;
                        c++;
                        goto A;
                    }
                }
            }
            if(c==n)
            {
                break;
            }
        }
        break;
    }
    sort(y,y+c,b);
    cnt=1;
    lr=y[1].r;
    for(int i=2; i<=c; i++)
    {
        if(y[i].l>lr)
        {
            cnt++;
            lr=y[i].r;
        }
    }
    cout<<cnt;
}
