#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[505];
int p[505];
bool flag[505];
long long ans=0;
int lb(int x){return x&-x;}
void dfs(int d,int wtg){
    if(n-wtg<m) return ;
    if(d>n){
        ans++;
        ans%=mod;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(flag[i]==0){
            p[d]=i;
            flag[i]=1;
            int x=0;
            if(s[d-1]-'0'==0||wtg>=c[i]) x=1;
            dfs(d+1,wtg+x);
            flag[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    dfs(1,0);
    cout<<ans;
}
