#include<bits/stdc++.h>
using namespace std;

const int N = 500+ 9;
const int mod=998244353;
long long n,m,ans=1;
string s;
int c[N];

int main(){

    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;++i){
        cin>>c[i];
    }
    for(int i=n;i>=1;--i){
        ans=ans*i%mod;
    }

    cout<<ans%mod<<endl;

    return 0;
}
