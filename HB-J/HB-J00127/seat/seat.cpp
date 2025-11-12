#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x=0,y=0;
    cin>>n>>m;
    int a[n][m],z[n*m];
    y+=n*m;
    for(int i=0;i<y;i++)
    {
        cin>>z[i];
    }
    x=z[0];
    sort(z,z+y);
    for(int i=0;i<y;i++)
    {
        if(z[i]==x)
        {
            cout<<i%m+1<<" "<<i%n+1;
        }
    }
    return 0;
}
