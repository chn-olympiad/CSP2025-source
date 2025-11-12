#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
struct r{
    bool x;
    long long c;
}a[501],b[501];
bool v[501];
string s;
inline void dfs(long long i){
    if(i==n){
        long long h=0,u=n;
        for(long long j=0;j<n;++j){
            long long _h=0;
            if(h>=b[j].c){
                --u;
                _h=1;
            }
            if(!(s[j]-'0')){
                _h=1;
            }
            h+=_h;
        }
        if(u>=m){
            ++ans;ans%=998244353;
        }
        return;
    }
    for(long long j=0;j<n;++j){
        if(!v[j]){
            v[j]=true;
            b[i]=a[j];
            dfs(i+1);
            v[j]=false;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=0;i<n;++i){
        cin>>a[i].c;
    }
    dfs(0);
    cout<<ans;
    return 0;
}
