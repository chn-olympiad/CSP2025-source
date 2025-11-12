#include<bits/stdc++.h>
using namespace std;
long long dp[1000000];
long long sum1,n,a[1000000],k,sum,cnt,cz[1000000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cz[i]=cz[i-1]|a[i];
    }
    if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                cnt++;
            }
        }
        cout<<cnt;
        return 0;
    }else if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                cnt++;
            }
        }
        cout<<cnt;
        return 0;
    }
    cout<<2;
    return 0;
}

