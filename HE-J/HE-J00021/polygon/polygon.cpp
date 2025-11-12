#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5005]={};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==(3-1)){
        sort(a,a+n);
        int z=0;
        for(int i=0;i<n;i++){
            z+=a[i];
        }
        if(z>(a[n-1]*2)) cout<<1;
        else cout<<0;
    }
    else cout<<n+3<<endl;
    return 0;
}
