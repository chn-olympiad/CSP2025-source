#include<bits/stdc++.h>
using namespace std;
long long n,k,a[555555],sum[555555],ssm,cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sum[1]=a[1];
    for(long long i=2;i<=n;i++){
        sum[i]=(sum[i-1]^a[i]);
    }
    if(k==0){
        if(n==2){
            cout<<2;
            return 0;
        }
        else if(n==1){
            cout<<0;
            return 0;
        }
        if(n%2!=0){
            cout<<n-1;
        }
        else{
            cout<<n;
        }
        return 0;
    }
    for(long long l=1;l<=n;l++){
        for(long long r=l;r<=n;r++){
            if(sum[r]^sum[l]==k){
                cnt=max(cnt,r-l);
                l=r+1;
            }
        }
    }
    cout<<cnt;
    return 0;
}
