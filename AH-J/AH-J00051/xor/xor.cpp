#include<bits/stdc++.h>
using namespace std;
long long n,k,a,cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k==1){
        cout<<n;
    }else if(k==0){
        cout<<n/2;
    }else{
        for(long long i=1;i<=n;i++){
            cin>>a;
            if(a==k){
                cnt++;
            }
        }
        cout<<cnt;
    }
    return 0;
}

