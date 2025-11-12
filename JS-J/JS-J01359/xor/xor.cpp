#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,arr[N],sum=0,ans=0;
bool all_same=true;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]!=arr[i-1]&&i!=1)all_same=false;
    }//teshuxingzhiA
    if(all_same){
        if(k==1){
            if(arr[1]==1)cout<<n;
            else cout<<0;
        }
        else{
            if(arr[1]==1)cout<<n/2;
            else cout<<n;
        }
    }//teshuxingzhiB
    else if(k<=1){
         int ans=0;
         if(k==0){
            for(int i=1;i<=n;i++){
                if(arr[i]==0||arr[i]==1&&arr[i+1]==1&&arr[i+2]!=1)ans++;
            }
         }
         else{
            for(int i=1;i<=n;i++){
                if(arr[i]==1)ans++;
            }
         }
         cout<<ans;
    }//xiaxiede
    else{
        //cerr<<"I AK CSP-J2 2025!!!!\n";
        int ans=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            sum^=arr[i];
            if(sum==k){
                ans++;
                sum=0;
            }
        }
        cout<<ans;
    }
    return 0;
}
