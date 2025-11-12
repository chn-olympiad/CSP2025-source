#include<bits/stdc++.h>
using namespace std;
const int N=1e6+20;
int a[N]={};
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long ans=0,cnt=-1;
    if(a[1]==k){
        ans++;
    }else{
        cnt=a[1];
    }
    for(int i=2;i<=n;i++){
        if((cnt^a[i])==k&&cnt>=0){
            ans++;
            cnt=-1;
        }else if(a[i]==k){
            ans++;
            cnt=-1;
        }else if(cnt==-1){
            cnt=a[i];
        }else{
            cnt=(a[i]^cnt);
        }
    }
    cout<<ans;
    return 0;
}
