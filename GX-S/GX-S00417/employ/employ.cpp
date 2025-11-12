#include<bits/stdc++.h>
using namespace std;
long long  n,m,arr[510],Mod=998244353;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(long long i=1;i<=n;i++)cin>>arr[i];
    long long ans=1,aa=1;
    for(long long i=1;i<=n;i++){
        ans=((ans%Mod)*(i%Mod))%Mod;
    }
    cout<<ans;
    return 0;
}

