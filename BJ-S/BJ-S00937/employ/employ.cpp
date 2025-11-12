#include<bits/stdc++.h>
using namespace std;
int s[505],c[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    unsigned long long ans;
    unsigned long long a=1,b=1;
    int n,m,x=0;
    cin>>n>>m;
    z=n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=m;i++){
        a*=(n+1-i);
        b*=(m+1-i);
    }
    ans=a/b;
    if(m==n&&x!=n){
        cout<<0;
    }
    else if(m==n&&x==n){
        cout<<1;
    }else{
        cout<<ans%998244353;
    }
    return 0;
}

