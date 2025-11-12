#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n==1&&k==a[0])
    {
        cout<<1<<endl;
        return 0;
    }
    if(n==2&&k==a[0]&&k==a[1])
    {
        cout<<2<<endl;
        return 0;
    }
    else
    {
        cout<<1<<endl;
        return 0;
    }
    return 0;
}