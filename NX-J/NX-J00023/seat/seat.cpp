#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[110],c,d=0;
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    c=a[0];
    sort(a,a+n*m);
    for(int i=0;i<n*m;i++)
    {
        if(c==a[i])
        {
            d=i;
            break;
        }
    }
    int e=d/m,f=d%m;
    if(e==0)
    {
        e++;
    }
    if(f==0)
    {
        f+=m;
    }
    cout<<e<<" "<<f;

    return 0;
}
