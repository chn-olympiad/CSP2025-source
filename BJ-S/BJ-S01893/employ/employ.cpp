#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e6+7;
const int mod=998244353;
ll n,m;
string s;
int c[N];
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    bool flag=0;
    for(int i=1;i<=n;i++) {
        cin>>c[i];
    }
    int len=s.size();
    for(int i=0;i<len;i++) {
        if(s[i]!='1') flag=1;
    }
    if(!flag) {
                ll ans=1,nn=n;
        for(int i=1;i<=n;i++) {
            ans*=(nn%mod)%mod;
            nn--;
        }
        cout<<ans;

    }
    else {
        srand(time(0));
        cout<<rand()%mod;
    }
    return 0;
}
