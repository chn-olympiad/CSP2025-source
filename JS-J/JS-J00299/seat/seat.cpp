#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,g=1,a,t;
    cin>>n>>m>>a;
    for(int i=2;i<=n*m;i++)
    {
        cin>>t;
        if(t>a) g++;
    }
    int al=g/n+1,ah;
    if(g%n==0) al--;
    if(al%2==0)
    {
        ah=n-g%n+1;
        if(ah==0) ah=1;
    }
    else
    {
        ah=g%n;
        if(ah==0) ah=n;
    }
    cout<<al<<" "<<ah<<endl;
    return 0;
}
