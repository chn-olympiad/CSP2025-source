#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],len,cnt,c[505];
long long ans,pp;
bool flag[505];
string s;
long long mod=998244353;
void check(){
    int p=0,t=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='1'&&p<c[i]){
            t++;
        }else{
            p++;
        }
    }
    if(t>=m) ans++;
    return;
}
void dfs(int x){
    if(x>n){
        check();
        return;
    }
    for(int i=1;i<=n;i++){
        if(flag[i]==0){
            flag[i]=1;
            c[i]=a[x];
            dfs(x+1);
            flag[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    s=' '+s;
    for(int i=1;i<=n;i++){
        if(s[i]=='1') cnt++;
    }
    if(n<=11){
        dfs(1);
    }
    cout<<(ans%mod);
    return 0;
}