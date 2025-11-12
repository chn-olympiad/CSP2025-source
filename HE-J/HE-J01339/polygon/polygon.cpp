#include <bits/stdc++.h>
using namespace std;
int n,a[100],sum=0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    if(sum>2*a[3]){
        cout<<1;
    }
    return 0;
}

