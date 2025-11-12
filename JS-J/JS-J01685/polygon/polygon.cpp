#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int p=998244353;
int power(int a,int b){
    int res=1%p;
    while(b){
        if(b&1)res=res*a%p;
        a=a*a%p;
        b>>=1;
    }
    return res%p;
}
int f[5005]={1,1},inv[5005]={1,1};
int C(int n,int m){
    return f[n]*inv[m]*inv[n-m];
}
void solve(){
    for(int i=2;i<=5000;i++){
        f[i]=f[i-1]*i%p;
        inv[i]=power(f[i],p-2)%p;
    }
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ma=*max_element(a.begin(),a.end());
    int sum{};
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    if(n<=3){
        if(sum>2*ma){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
        return ;
    }
    if(ma<=1){
        int ans{};
        for(int i=3;i<=n;i++){
            ans+=C(n,i);
        }
        cout<<ans<<endl;
    }
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}