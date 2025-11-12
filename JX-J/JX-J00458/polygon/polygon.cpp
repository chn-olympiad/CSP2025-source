#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    long long a[5001]={},s=0,mod=998244353,ans=2;
    if(n%2!=0){
        for(int i=3;i<=n;i++){
            int b=i;
            for(int j=n;j>=n-i+1;j--){
                ans=(ans*j/b)%mod;
                b--;
            }
            s+=ans%mod;
        }
    }
    cout<<s;
    return 0;
}
//^
//4 2
//2 1 0 3
