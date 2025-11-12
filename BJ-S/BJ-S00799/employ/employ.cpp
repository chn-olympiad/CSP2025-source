#include <bits/stdc++.h>
using namespace std;
long long n,x;
string s;
const long long MOD=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>x;
    cin>>s;
    int t=n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        if(a==0) t--;
    }
    long long ans=1;
    for(int i=1;i<=t;i++){
        ans*=i;
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}