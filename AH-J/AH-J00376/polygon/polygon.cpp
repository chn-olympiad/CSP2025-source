#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],cnt,k;
long long f(long long x){
    long long t=1;
    for(long long i=1;i<=x;i++){
        t*=i;
    }
    return t;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    k=f(n);
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        cnt+=k/f(n-i)/f(i);
        cnt%=998244353;
    }
    cout<<cnt;
    return 0;
}
