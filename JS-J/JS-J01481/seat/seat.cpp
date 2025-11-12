#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int cmp=0,larger=0;
    for(int i=1;i<=n*m;i++)
    {
        int x;
        cin>>x;
        if(i==1)
        {
            cmp=x;
        }
        if(x>=cmp)
        {
            larger++;
        }
    }
    int L=ceil(larger*1.0/m);

    if(larger%(2*m)==0)
    {
        cout<<L<<' '<<1;
        return 0;
    }
    larger%=(2*m);
    if(larger<=m)
    {
        cout<<L<<' '<<larger;
    }
    else
    {
        cout<<L<<' '<<(m-larger%m+1);
    }
    return 0;
}
