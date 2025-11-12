#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c,r,a;
    cin>>n>>m;
    int s=0;
    s=n*m;
    int a1,a2,ai;
    cin>>a>>a1>>a2>>ai;
    if(a>a1>a2>ai){
        cout<<"1,1";
    }
    else
    cout<<c<<","<<r;
    return 0;
}
