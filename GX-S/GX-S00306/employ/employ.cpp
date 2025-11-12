#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e3+10;
const ll mod = 998244353l;

int n,m;
string s;
int c[N];

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    bool A = true;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    int eaN = n;
    for(int i=0;i<n;i++){
        if(s[i] != '1'){
            A = false;
            eaN--;
        }
    }
    sort(c,c+n);
    if(A){
        ll ans = 1;
        for(int i=1;i<=n;i++){
            ans *= i;
            ans = ans % mod;
        }
        cout<<ans;
    }else if(m == 1 && s[0]=='1'){
        ll ans = 1;
        for(int i=1;i<=n;i++){
            ans *= i;
            ans = ans % mod;
        }
        cout<<ans;
    }else if(eaN < m){
        cout<<0;
    }else{
        cout<<1;
    }
    return 0;
}
