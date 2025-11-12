#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n,cnt,ma;
int a[5020];
ll ans;
void dfs(int t,string s){
    if(t==n){
        cnt=0,ma=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt+=a[i+1];
                ma=max(ma,a[i+1]);
            }
        }
        if(cnt>2*ma)ans++;
        return;
    }
    dfs(t+1,s+"0");
    dfs(t+1,s+"1");
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    bool s1=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1)s1=0;
    }
    if(s1){
        cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1)cnt++;
        }
        ans=1;
        for(int i=1;i<=cnt;i++){
            ans=ans*2;
            ans%=mod;
        }
        ans=ans-1ll-(ll)cnt-(ll)(cnt*(cnt-1)/2);
        cout<<ans;
        return 0;
    }
    dfs(0,"");
    cout<<ans;
    return 0;
}
