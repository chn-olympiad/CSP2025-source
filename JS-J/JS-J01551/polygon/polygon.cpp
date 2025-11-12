#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int j;
const int mod=998244353;
long long  ans=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
      cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]>a[n]){
                ans+=n-2;
            }
        }
    }
    cout<<(ans+3)%mod;
    return 0;
}

