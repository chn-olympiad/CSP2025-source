#include <bits/stdc++.h>
using namespace std;
long long zw[15][15];
long long cj[230];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long m,n;
    cin>>n>>m;
    for(int i=1;i<=m*n;i++)
    {
        cin>>cj[i];
    }
    int rcj=cj[1];
    sort(cj,cj+n*m);
    for(int i=1;i<=n*m;i++)
    {
        if(cj[i]=rcj)
        {
            if(n==1)
               cout<<1<<" "<<i;
            else if(m==1)
                cout<<i<<" "<<1;
            break;
        }
    }
    return 0;
}
