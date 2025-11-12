#include<bits/stdc++.h>
using namespace std;
int n,k,a[20005],m;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]==1)break;
        m++;
    }
    if(k==0)cout<<m;
    else cout<<n-m;
    return 0;
}
