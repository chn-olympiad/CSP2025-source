#include<bits/stdc++.h>
using namespace std;
int n,m,s[501],c[501];
long long ans;
int main(){
    freopen("employ.in","r",stdin);
    cin>>n>>m;
    bool he=1,xian=1;
    for(int i=1;i<=n;i++){
        cin>>s[n];
        if(s[n]==0)he=0;
        if(s[n]==1)xian=0;
    }
    for(int i=1;i<=n;i++){
        cin>>c[n];
    }
    if(xian==1){cout<<0;return 0;}
    if(he==1){
        if(n==1){cout<<1;return 0;}
        ans=1;
        for(int i=2;i<=n;i++){
            ans*=i;
        }
    }
    else{
        if(m==n){cout<<0;return 0;}
    }
    cout<<ans%998244353;
    freopen("employ.out","w",stdout);
    return 0;
}
