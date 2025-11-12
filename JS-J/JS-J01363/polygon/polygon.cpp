#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long cnt=0,x=0,flag=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)flag=1;
    }
    if(flag==0){
        for(int i=1;i<=n-2;i++){
            cnt+=pow(2,n-2-i)*(x+i);
            x+=i;
            cnt=cnt%998244353;
        }
        cout<<cnt;
        return 0;
    }
    else if(n==3){
        if(a[1]+a[2]+a[3]<=2*a[1]||a[1]+a[2]+a[3]<=2*a[2]||a[1]+a[2]+a[3]<=2*a[3]){
            cout<<0;
        }
        else cout<<1;
    }
    return 0;
}
