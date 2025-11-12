#include<bits/stdc++.h>
using namespace std;
const long long q=998244353;
long long n,k,a[1000000],sum,maxi,midi,mini,ans;
long long happy(long long x){
    if(x==1||x==0)return 1;
    return x*happy(x-1)%q;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(n==3){sort(a+1,a+n+1);
    if(a[1]+a[2]>a[3]){
        cout<<1;
    }
    else{
        cout<<0;
    }}
    if(sum==n){
        cout<<(n-1)*(n-2)%q/2%q;
    }
     return 0;

}
