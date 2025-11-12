#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
const int MOD=998244353;
int n,m,cnt=0,sum0=0;
string s;
int c[N],res[N];
bool vis[N],fl=1;
void init(){
    res[1]=1;
    for(int i=2;i<=n;i++){
        res[i]=(res[i-1]*i)%MOD;
    }
    return ;
}
ll dfs(int dt,int pp,int now){
    ll ans=0;
    if(dt==n){
        if(pp>=m){
            return 1;
        }else{
            return 0;
        }
    }

    if(pp==m){
        return res[n-dt];
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            bool p=((dt-pp)<c[i])&&(s[dt+1]-'0');
            ans+=dfs(dt+1,pp+p,i);
            ans%=MOD;
            vis[i]=0;
        }
    }
    return ans;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>s;
    s=' '+s;
    init();
    for(int i=0;i<s.length();i++){
        if(s[i]-'0'==1){
            cnt++;
        }else if(s[i]-'0'==0){
            fl=0;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0){
            sum0++;
        }
    }
    sort(c+1,c+1+n);
    if(cnt<m){
        cout<<0;
        return 0;
    }
    if(m==n){
        cout<<(c[1]>=1)?1:0;
        return 0;
    }
    cout<<dfs(0,0,0);
    return 0;
}
