#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[505],c[505];
bool vis[505];
int p[505];
int n,m;
long long ans;
void ch(){
    int cnt=0,cnt2=0;
    for(int i=1;i<=n;i++){
        if(cnt>=c[p[i]]){
            cnt++;
            continue;
        }
        if(a[i]==0){
            cnt++;
            continue;
        }
        cnt2++;
    }
    if(cnt2>=m){
        ans++;
        ans%=MOD;
    }
}
void dfs(int i,int k){
    p[k]=i;
    if(k>=n){
        ch();
        return;
    }
    for(int j=1;j<=n;j++){
        if(!vis[j]){
            vis[j]=1;
            dfs(j,k+1);
            vis[j]=0;
        }
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++) a[i]=(int)s[i-1]-48;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++){
        vis[i]=1;
        dfs(i,1);
        vis[i]=0;
    }
    cout<<ans;
    return 0;
}
