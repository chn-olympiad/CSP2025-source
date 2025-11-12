#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int pos=1;
    int r;
    cin>>r;
    for(int o,i=2;i<=n*m;i++)
    {
        cin>>o;
        if(r<o) pos++;
    }
    int l=int(floor((pos-1)/n))+1,h;
    if(l%2==1) h=(pos-(l-1)*n);
    else h=n-(pos-(l-1)*n)+1;
    cout<<l<<' '<<h;
    return 0;
}