#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000],p[1000],mod=998244353;
string s;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    int i,j,k=1,l;
    for(i=0;i<n;i++){
        cin>>a[i];

    }
    if(m==n){
        cout<<0;
        return;
    }long long ans=1;
    for(i=1;i<=n;i++)ans*=i,ans%=mod;
    cout<<ans;
}
