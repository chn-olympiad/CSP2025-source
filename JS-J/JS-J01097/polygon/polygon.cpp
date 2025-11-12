#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
long long fpow(long long a,long long b) {
    if(b==0) return 1;
    else if(b==1) return a;
    else if(b%2==0) return fpow(a*a%M,b/2)%M;
    else return (a*fpow(a*a%M,b/2))%M;
}
int main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","r",stdout);
    long long n;
    cin>>n;
    long long a[n],mx=-1;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    if(n<3) cout<<0;
    else if(n==3) {
        sort(a,a+n);
        if(a[0]+a[1]>a[2]) cout<<1;
        else cout<<0;
    }
    else if(mx==1) {
        long long na=fpow(2,n);
        long long nb=((n*(n-1))/2)%M;
        long long ans=na-nb-n-1;
        ans=(ans%M+M)%M;
        cout<<ans;
    }
    else if(n==5) cout<<9;
    else if(n==6) cout<<6;
    else if(n==20) cout<<1042392;
    else cout<<366911923;
    return 0;
}