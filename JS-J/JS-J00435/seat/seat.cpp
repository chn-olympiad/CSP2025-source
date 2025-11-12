#include<bits/stdc++.h>
using namespace std;
struct node
{
    int c;
    bool f;
} a[101];
bool cmp(node x,node y)
{
    return x.c>y.c;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,z,l,h;
    cin>>n>>m;
    z=n*m;
    a[1].f=1;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i].c;
    }
    sort(a+1,a+z+1,cmp);
    for(int i=1;i<=z;i++)
    {
        if(a[i].f)
        {
            l=(i+n-1)/n;
            if(l%2==0)
            {
               h=n-(i%n)+1;
            }
            else
            {
                h=i%n;
                if(h==0)
                {
                    h=n;
                }
            }
            cout<<l<<' '<<h;
            break;
        }
    }
    return 0;
}