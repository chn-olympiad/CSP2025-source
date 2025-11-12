#include<bits/stdc++.h>
using namespace std;
const int maxx=1e5+5,mod=998244353;
int n,m,vis[maxx],a[maxx],ans;
string s;
vector <int> v;
void f(){
    int kill=0,win=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'||kill>=a[v[i]-1]) {
            kill++;
            continue;
        }else win++;
    }
    if(win>=m) ans++;
}
void qpl (int x){
    if(x==n+1){
        f();
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;
        v.push_back(i);
        qpl(x+1);
        v.pop_back();
        vis[i]=0;
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    qpl(1);
    cout<<ans%mod;
    return 0;
}
