#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=520,mod=998244353;
int n,m,c[N],ans=0;
string s;
bool a[N],vis[N];
int cal(int x){
    if(x<0)return 0;
    int num=1;
    for(int i=2;i<=x;i++)
    {
        num=(num*i)%mod;
    }
    return num;
}
void dfs(int x,int cnt){
    if(cnt==m){
        ans=(ans+cal(n-x+1))%mod;
        return;
    }
    if(x>n){
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        vis[i]=1;
        //cout<<x<<" "<<i<<" "<<cnt<<endl;
        if(x-cnt-1<c[i]&&a[x])
            dfs(x+1,cnt+1);
        else
            dfs(x+1,cnt);
        vis[i]=0;
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<s.size();i++){
        a[i+1]=s[i]-'0';
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(m==n){
        bool flag=1;
        for(int i=1;i<=n;i++){
            if(!a[i]||c[i]==0)
            {
                flag=0;
                break;
            }
        }
        if(!flag){
            cout<<"0"<<endl;
            return 0;
        }
        cout<<cal(n)<<endl;
    }
    else if(n<=18){
        memset(vis,0,sizeof(vis));
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
