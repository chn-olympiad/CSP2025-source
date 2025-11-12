#include<bits/stdc++.h>
using namespace std;
string s;
int ans=1;
int m,n,q=1,jj=0,nx[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    int u=n;
    cin>>s;
    for(int i=1;i<=u;i++){
        cin>>nx[i];
    }
        for(int i=1;i<=n;i++){
        ans=ans*i;
        ans=ans%998244353;
    }
    cout<<ans;


    return 0;
}
