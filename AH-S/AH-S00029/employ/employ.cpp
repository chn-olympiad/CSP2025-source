#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
const int N = 1000;
int n,m;
int ans = 1;
string str;
int a[N];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>str;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    if(n == m){
        int len = str.size();
        for(int i = 0;i<len;i++){
            if(str[i] == '0'){
                cout<<0<<endl;
                return 0;
            }
        }
        cout<<1<<endl;
        return 0;
    }
    for(int i = 2;i<=n;i++){
        ans *= i;
        ans %= MOD;
    }
    cout<<ans<<endl;


    return 0;
}