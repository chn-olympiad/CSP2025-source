#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt;
int a[1005],f[1005],t[1005];
string s;
void ff(){
    int nu=0,cntt=0;
    for(int i=1;i<=n;i++){
        if(nu<t[i]&&s[i-1]=='1') {
            cntt++;
            if(cntt>=m) break;
        }
        else nu++;
    }
    if(cntt>=m) cnt=(cnt+1)%998244353;
}
void dfs(int x){
    if(x==n+1){
        ff();
        return;
    }
    for(int i=1;i<=n;i++){
        if(f[i]==0){
            t[x]=a[i];
            f[i]=1;
            dfs(x+1);
            f[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1);
    cout<<cnt;
    return 0;
}
