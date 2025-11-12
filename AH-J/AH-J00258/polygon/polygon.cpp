#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //n:3
    //n:4
    //n:5
    //n:~~~
    //n:n
    ll sum=0;
    for(int i=3;i<=n;i++){
        ll num=1;
        for(int j=1;j<=i;j++){
            num=((num%998244353)*((n-i+j)%998244353))%998244353;
        }
        for(int j=1;j<=i;j++){
            num/=j;
        }
        sum=((sum%998244353)+(num%998244353))%998244353;
    }
    cout<<sum%998244353;
    return 0;
}

