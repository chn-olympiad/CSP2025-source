#include<iostream>
using namespace std;
int c[505];
int n,m;
long long mod=998244353;
int p[505];
int v[505];
long long ans;
string a;
void dfs(int k){
    if(k==n){
        int cnt=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(a[i-1]=='0'||c[p[i]]<=cnt){
                cnt++;
            }
            else{
                sum++;
            }
        }
        if(sum>=m){
            ans++;
            ans%=mod;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!v[i]){
            p[i]=k+1;
            v[i]=1;
            dfs(k+1);
            v[i]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>a;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    dfs(0);
    cout<<ans;
    return 0;
}
