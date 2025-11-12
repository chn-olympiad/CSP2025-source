#include <bits/stdc++.h>

using namespace std;
int n,cnt;
int a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==3){
        int n=a[1]+a[2];
        int n1=a[2]+a[3];
        int n2=a[1]+a[2]+a[3];
        if(n>a[2]*2)cnt++;
        if(n1>a[3]*2)cnt++;
        if(n2>a[3]*2)cnt++;
        cout<<cnt;
        return 0;
    }

    return 0;
}

