#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,t,b=0;
    cin>>n,t;
    int a[n];
    cin>>a[0]>>a[1];
    if(a[0]==0)b++;
    if(a[1]==0)b++;
    cout<<b;
    return 0;
}
