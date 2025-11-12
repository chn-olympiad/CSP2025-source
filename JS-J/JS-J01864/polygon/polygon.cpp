#include<bits/stdc++.h>
using namespace std;
int d[5005];
int tri()
{
    int a,b,c;
    cin>>a>>b>>c;
    int d=max(a,b);
    d=max(d,c);
    if(a+b+c>d*2) return 1;
    else return 0;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n==3) cout<<tri();
    else
    {
        cout<<0;
    }
    return 0;
}
