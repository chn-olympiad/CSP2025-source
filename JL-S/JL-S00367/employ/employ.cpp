#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int N = 510;
const int mod = 998244353;
int n,m,ans,k,fir,a[N];
char s[N];

bool check(){
    bool flag=1;
    for(int i=1;i<=n;i++) {
        if(s[i]=='0') {
            if(flag) fir=i;
            flag=0; 
        }
        else k++; 
    }
    return flag;
}

namespace sub1{
    void solve(){
        int p=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='1'&&a[i]>=p) ans++;
            else p++;
        }
        cout<<ans;
    }
}

namespace sub2{
    void solve(){
        for(int i=1;i<=n;i++){
            if(s[i]=='0') {
                cout<<0;
                return;
            }
        }
        cout<<1;
    }
}

namespace sub3{
    void solve(){
        do{
            int p=0;
            for(int i=1;i<=n;i++) {
                if(s[i]=='0') p++;
                else if(a[i]>=p) ans++;
            }
        }while(next_permutation(a+1,a+n+1));
        cout<<ans;
    }
}

namespace sub4{
    void solve(){
        int p=1;
        ans=((fir-1)*fir/2%mod)%mod;
        for(int i=fir+1;i<=n&&p<=k;i++){
            if(s[i]=='1'&&a[i]>=p) ans=(((ans+1)*ans)%mod)%mod;
            else {
                p++;
                ans=ans/i/p;
            }
        }
        cout<<ans;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s+1;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1) sub1::solve();
    else if(m==n) sub2::solve();
    else if(check()) cout<<0;
    else if(k<=18) sub4::solve();
    else sub3::solve();
    return 0;
}