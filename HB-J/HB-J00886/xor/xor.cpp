#include<bits/stdc++.h>
using namespace std;
#define tshe 1919810
typedef ll long long;
bool ns2=true,ns256=true;
ll n,k,a[tshe],sum,us2,us256;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        if(a[i]>1){
            ns2=false;
            if(a[i]>256)ns256=false;
        }
    }if(ns2 && sum==n){
        if(n%2==0){
            if(k==1)cout<<n;
            else if(k==0) cout<<n/2;
            else cout<<0;
        }else{
            if(k==1)cout<<n;
            else if(k==0)cout<<n/2;
            else cout<<0;
        }
        return 0;
    }else if(ns2 && sum<n){
            
    }else if(ns256){

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}