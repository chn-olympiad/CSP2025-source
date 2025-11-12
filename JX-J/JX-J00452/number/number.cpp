#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define INF 0x3f3f3f3f
#define endl '\n'
#define pow po_w
using namespace std;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while (ch<'0' or ch>'9') {if (ch=='-')  f=-f;ch=getchar();}
    while (ch>='0' and ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll po_w(ll x,ll y,ll mod){
    ll ans=1;
    while (y){
        if (y&1)
            ans*=x;
        x*=x;
        y>>=1;
        x%=mod;
        ans%=mod;
    }
    return ans;
}
ll gcd(ll x,ll y){
    if (y==0)
        return x;
    return gcd(y,x%y);
}
string a;
int cnt[15];
void solve(){
    cin>>a;
    int n=a.length();
    for (int i=0;i<n;i++){
        if (a[i]>='0' and a[i]<='9')
            cnt[a[i]-'0']++;
    }
    for (int i=9;i>=0;i--)
        while (cnt[i]--)
            cout<<i;
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ll t=1;
    // t=read();
    while (t--)
        solve();
    return 0;
}