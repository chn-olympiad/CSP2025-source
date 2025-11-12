#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long long n,m;
string s;
long long c[1000000];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    int n1 = n;
    for(int i = 0;i<n;i++){
        cin>>c[i];
        if(c[i] == 0){
            n1--;
        }
    }
    cout<<n1<<endl;
    long long ans = 1;
    for(long long i = n1;i>=1;i--){
        ans = (ans*i) % MOD;
        ans = ans % MOD;
    }
    cout<<ans;
}
