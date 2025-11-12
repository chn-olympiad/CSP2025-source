#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a[50005],dp[50005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n-1);
    if(n==3){
        if(a[0]+a[1]>a[2]) cout<<1;
        if(a[0]+a[1]<=a[2]) cout<<0;
    }

    return 0;
}
