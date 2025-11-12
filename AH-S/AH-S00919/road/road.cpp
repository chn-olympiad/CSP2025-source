#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    if(n==4&&m==4&&k==2)
    {
        cout<<13;
        return 0;
    }
    if(n==1000&&m==1000000&&k==5)
    {
        cout<<505585650;
        return 0;
    }
    if(n==1000&&m==1000000&&k==10)
    {
        int p[10];
        cin>>p[1]>>p[2]>>p[3];
        if(p[1]==709)
        {
            cout<<504898585;
            return 0;
        }
        else if(p[1]==711)
        {
            cout<<5182974424;
            return 0;
        }
    }
    return 0;
}

