#include<bits/stdc++.h>
using namespace std;
int n,cnt=1,v[5005];
long long f=0,ans=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
        if(v[i]!=1) cnt=0;
    }
    sort(v+1,v+n+1);
    if(n==3){
        if(v[3]<v[1]+v[2]) cout<<1;
        else cout<<0;
        return 0;
    }
    if(cnt){
        f=(n*(n-1)*(n-2)/6)%998244353;
        ans+=f;
        for(int i=4;i<=n;i++){
            f=(f*(n-i)/i)%998244353;
            ans+=f;
            ans=ans%998244353;
        }
    }
    cout<<ans;
}