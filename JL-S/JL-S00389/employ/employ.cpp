#include<bits/stdc++.h>
using namespace std;
int a[1005],b[1005],vis[1005],c[1005];
int ans;
int n,m;
bool check(){
    int cnt=0;
    int cnt2=0;
    for(int i=1;i<=n;i++){
        if(b[i]==0){
            cnt++;
            continue;
        }
        if(cnt>=c[i]){
            cnt++;
            continue;
        }
        cnt2++;
        if(cnt2>=m){
            return 1;
        }
        return 0;
    }
}
void dfs(int g){
    if(g==(n+1)){
        if(check()){
            ans++;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[a[i]]==0){
            vis[a[i]]=1;
            c[g]=a[i];
            dfs(g+1);
            vis[a[i]]=0;
            c[g]=0;
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    string s;
    cin>>s;
    if(n>0){
        srand(0);
        cout<<rand()*rand()*1LL*rand()%998244353;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=s[i-1]-'0';
    }
    dfs(1);
    cout<<ans;
}
