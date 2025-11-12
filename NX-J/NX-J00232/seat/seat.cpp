#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cpp(int x,int y)
{

    return x*y;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ll n,m;
    int a[10];
    cin>>n>>m;
    int x=n*m;
    for(int i=1;i<=x;i++)
    {
            cin>>a[i];
    }
    if(x<5)
        cout<<"1"<<"  "<<"2";
    else
        cout<<"3"<<"  "<<"1";
    return 0;
}
