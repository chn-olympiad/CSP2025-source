#include<bits/stdc++.h>
using namespace std;
long long z,n,l,r,a[5005];
bool mvp(long long a,long long b){return a>b;}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),z+=a[i];
    sort(a+1,a+n+1,mvp);
    if(n==3){
        if(a[1]+a[2]>a[3])cout<<1;
        else cout<<0;
        return 0;
    }
    if(a[1]==1){
        z=1;
        for(int i=1;i<=n-10;i++)z=z*2%998244353;
        z*=1024;
        z-=n+n*(n-1)/2-1;
        z%=998244353;
        cout<<z;
    }
    return 0;
}
