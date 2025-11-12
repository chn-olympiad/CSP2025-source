#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,z,p=1,h,l;
    cin>>n>>m>>z;
    for(int i=2;i<=m*n;i++)
    {
        int a;
        cin>>a;
        if(a>z) p++;
    }
    l=(p-1)/n+1;
    h=p-(l-1)*n;
    if(l%2==0) h=n-h+1;
    cout<<l<<' '<<h<<'\n';
    return 0;
}
