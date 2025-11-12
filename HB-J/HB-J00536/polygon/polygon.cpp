#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ret,md=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==3){
        sort(a+1,a+4);
        if(a[1]+a[2]>a[3]&&a[3]-a[2]<a[1]){
            cout<<1;
        }
        else cout<<0;
        return 0;
    }
    ret=1;
    for(int i=1;i<=n;i++) ret=(ret*2)%md;
    cout<<(ret+md-1-n-n*(n-1)/2)%md;
}