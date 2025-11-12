#include<bits/stdc++.h>

using namespace std;

const int mod=998244353;
int n,m;
string s;
int c[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }

    long long int ans=1;
    for(int i=n;i>=1;i--){
        ans*=i;
        ans%=mod;
    }
    cout<<ans;

    return 0;
}

