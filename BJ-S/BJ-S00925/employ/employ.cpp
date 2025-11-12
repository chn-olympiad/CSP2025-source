#include<bits/stdc++.h>
using namespace std;
int c[505];
int maxn=-1001,ma=998244353,n,m,cnt=0;
bool flag=0;
string s;
void solve(){
    long long ans=1;
    for(int i=1;i<=n-cnt+1;i++){
        ans=ans*i%ma;
    }
    cout<<ans;
}
int main(){

    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        maxn=max(maxn,c[i]);
        if(c[i]==0) cnt++;
    }
    for(int i=1;i<=s.length();i++){
        if(s[i]==0) flag=0;
    }
    solve();
    return 0;
}
