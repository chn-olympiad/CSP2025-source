#include<bits/stdc++.h>
using namespace std;
int len[5005]={0};
int n,ans=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>len[i];
    }
    if(n==3){
        if(len[1]+len[2]>len[3]) cout<<1;
        else cout<<0;
        return 0;
    }
    for(int i=3;i<=n;i++){
        int a=1,b=1;
        for(int j=n;j>=n-i+1;j--){
            a*=j;
            a%=998244353;
        }for(int j=i;j>=1;j--){
            b*=j;
            b%=998244353;
        }ans+=a/b;
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}
