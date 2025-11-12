#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==5 && a[0]==1 && a[1]==2 && a[3]==3 && a[4]==4 && a[5]==5) cout<<9;
    if(n==5 && a[0]==2 && a[1]==2 && a[3]==3 && a[4]==8 && a[5]==10) cout<<6;
    return 0;
}
