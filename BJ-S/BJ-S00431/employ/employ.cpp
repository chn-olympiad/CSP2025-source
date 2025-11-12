#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;

int n,m;
int a[505],box[505],vis[505];
int ans;

string s;
void dfs(int cur){
    if(cur==n){
        int cnt=0,tot=0;
        for(int i=0;i<n;i++){
            int flag=1;
            if(s[i]=='0')   flag=0;
            if(cnt>=a[box[i]])  flag=0;
            if(flag==0) cnt++;
            else tot++;
        }
        if(tot>=m)  ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])  continue;
        vis[i]=1;
        box[cur]=i;
        dfs(cur+1);
        vis[i]=0;
    }
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    int flag=1;
    for(int i=0;i<s.size();i++){
        if(s[i]==0) flag=0;
    }
    for(int i=1;i<=n;i++)   cin>>a[i];
    if(n<=10){
        ans=0;
        dfs(0);
        cout<<ans<<'\n';
    }
    else if(flag==1){
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=mod;
        }
        cout<<ans<<'\n';
    }
    else cout<<0<<'\n';
    return 0;
}
