#include<iostream>
using namespace std;
int a,b,c;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    int v[105];
    cin>>n;
    if(n==3)
    {
        cin>>a>>b>>c;
        if(a+b+c>max(max(a,b),c)*2)
            cout<<1;
        else
            cout<<0;
        return 0;
    }
    return 0;
}
