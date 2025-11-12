#include<bits/stdc++.h>
using namespace std;
int bian[5005];
long ans=0,snas,mod=998244353;
int cs(int n,int m){
    int ans1=1;
    for(int i=n;i>=n-m+1;i--){
        ans1=ans1*i%mod;
    }
    int ans2=1;
    for(int i=m;i>=1;i--) ans2*=i;
    return ans1/ans2;
}
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,cnt=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>bian[i];
        if(i>1 && bian[i]==bian[i-1]) cnt++;
    }
    if(cnt==n){
        for(int i=3;i<=n;i++){
            ans+=cs(n,i)%mod;
        }
        cout<<ans;
    }
    else{
        sort(bian+1,bian+1+n,cmp);
       if(bian[1]<bian[2]+bian[3]) ans++;
       cout<<ans;
    }
    return 0;
}
