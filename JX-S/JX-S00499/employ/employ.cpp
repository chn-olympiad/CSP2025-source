#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
const ll N = 1e3+2;
ll n,m,a[N];
string s;
ll p(ll n){
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum=pow(n,i);
    }
    return sum;
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d",&n,&m);
    cin >> s;
    ll sum=0;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        if(s[i]=='1'){
            sum += p(a[i]);
        }
        else if(s[i] == '0')a[i]=1;
    }
    cout << sum % mod;
    return 0;
}
