#include<bits/stdc++.h>
using namespace std;
int a[1000005],n,k,m,f=0;
int main(){
    freopen("polygon.in",stdin);
    freopen("polygon.out",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=2){
        cout<<0;
        return 0;
    }
    if(a[1]+a[2]+a[3]>2*a[1]&&a[1]+a[2]+a[3]>2*a[2]&&a[1]+a[2]+a[3]>2*a[3])cout<<1;
    else cout<<0;
}
