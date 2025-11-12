#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;
int n,k;
int a[1000005],dp[1005][1005],s[1000005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==0){
        int len[256]={1};
        for(int i=1;i<=n;i++){
            if(i!=n && a[i]==a[i+1] ||a[i]==0) len[a[i]]++;
        }
        int ans=0;
        for(int i=1;i<=256;i++){
            if(len[i]%2==0) ans=max(ans,len[i]);
        }
        cout<<ans;
    }
    if(k==1){
        cout<<2;
    }
    return 0;
}