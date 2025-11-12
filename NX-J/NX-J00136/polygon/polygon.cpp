#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.cpp.in","r",stdin);
    freopen("polygon.cpp.out","w",stdout);
    int n,q,co=0;
    int w[10000];
    int i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>q;
        w[i]+=q;
    }
    for(int ii=1;ii<=3;ii++)
    {
        for(int j=0;j<=w[i];j++)
        {
            cout<<i*j;
        }
    }
    return 0;
}
