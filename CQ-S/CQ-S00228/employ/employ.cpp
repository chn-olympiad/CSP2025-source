#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500+5,mod=998244353;
int n,m,c[N],f[N];
ll ans;
string s;
void dfs(int x,int i,int cnt,int out){
    if(i>n){
        (ans+=(cnt>=m))%=mod;
        // cout<<"__________\n";
        return ;
    }
    // cout<<x<<" "<<cnt<<"\n";
    if(out>=c[x]){
        bool p=0;
        for(int j=1;j<=n;j++){
            if(f[j]==0){
                f[j]=1,p=1;
                dfs(j,i+1,cnt,out+1);
                f[j]=0;
            }
        }
        if(!p) dfs(x,i+1,cnt,out+1);
    }
    else{
        bool p=0;
        for(int j=1;j<=n;j++){
            if(f[j]==0){
                f[j]=1,p=1;
                dfs(j,i+1,cnt+s[i]-'0',out+(s[i]=='0'?1:0));
                f[j]=0;
            }
        }
        if(!p) dfs(x,i+1,cnt+s[i]-'0',out+(s[i]=='0'?1:0));
    }
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s=' '+s;
    ll t=1;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        (t*=i)%=mod;
    }
    if(m==n){
        bool x=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0'){
                x=1;
                break;
            }
        }
        if(x) cout<<0;
        else cout<<t;
        return 0;
    }
    for(int i=1;i<=n;i++){
        memset(f,0,sizeof f);
        f[i]=1;
        dfs(i,1,0,0);
        f[i]=0;
    }
    cout<<ans;
    return 0;
}
//25pts
/*
怎么说呢？大概就是不停地在吃东西吧。
也不知道坐我旁边的人什么想法。哈哈。
别人：综合竞赛两手抓
我：两只手都被抓了
*/