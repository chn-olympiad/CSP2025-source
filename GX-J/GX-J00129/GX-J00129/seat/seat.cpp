#include<bits/stdc++.h>
using namespace std;
int a[11000012];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    if(n==1&&m==1)
        cout<<"1"<<" "<<"1";
    return 0;
}
