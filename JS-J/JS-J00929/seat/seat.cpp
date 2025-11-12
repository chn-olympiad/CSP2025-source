#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>n>>m;
    int a,z;
    cin>>a;
    int w=1;
    for(int i=2;i<=m*n;i++)
    {
        cin>>z;
        if(z>a)w=w+1;
    }
    int c=1,r=1;
    c=(w-1)/4+1;
    r=(w-1)%(2*n);
    if(r<4)r=r+1;
    if(r>=4)r=8-r;
    cout<<c<<" "<<r;
    return 0;
}
