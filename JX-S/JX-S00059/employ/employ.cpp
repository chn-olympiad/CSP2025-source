#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int c[n+1];
    for(int i=1;i<=n;i++)cin>>c[i];
    long long ans=1;
    for(long long i=n;i>=1;i--){
        ans*=i;
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}
