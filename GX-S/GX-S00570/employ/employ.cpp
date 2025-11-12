#include<bits/stdc++.h>
using namespace std;
int n,m,x;
string s;
int sum=0;
long long ans=1;
int mod=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;

    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x!=0) sum++;
    }
    if(sum<m){
        cout<<0;
        return 0;
    }
    //cout<<n;
    for(int i=1;i<=n;i++){
        ans*=i;
        ans%=mod;
    }
    cout<<ans;
    return 0;
}

