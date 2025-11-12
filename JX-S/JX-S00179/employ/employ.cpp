#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,cnt,res,ans;
int a[2020],c[2020];
bool vis[2020];
char l;
void dfs(int t,string s){
    if(t==n){
        cnt=0,res=0;
        for(int i=0;i<n;i++){
            if(a[i+1]&&cnt<c[s[i]-'0']){
                res++;
            }else{
                cnt++;
            }
        }
        if(res>=m){
            //cout<<s<<" "<<res<<endl;
            ans++;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            dfs(t+1,s+(char)('0'+i));
            vis[i]=0;
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    bool s1=1;
    for(int i=1;i<=n;i++){
        cin>>l;
        a[i]=l-'0';
        if(a[i]==0)s1=0;
    }
    cnt=0;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0)cnt++;
    }
    if(s1){
        ans=1;
        if(n-cnt<m){
            cout<<0;
            return 0;
        }
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=mod;
        }
        cout<<ans;
        return 0;
    }
    dfs(0,"");
    cout<<ans;
    return 0;
}
