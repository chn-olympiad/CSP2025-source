#include <iostream>
#include <cstdio>
#define MAXN 505
#define MOD 998244353
using namespace std;
typedef long long ll;
int n,m;
string s;
bool vis[MAXN];
int pr[MAXN];
ll c[MAXN],ans;
void dfs(int x,int cnt){
    if(n-cnt<m) return ;
    if(x==n+1){
        if(n-cnt>=m) ans++;
        ans%=MOD;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            pr[x]=i;
            if(s[x]=='0'||cnt>=c[i]){
                //cout<<i<<" "<<cnt<<" "<<c[i]<<endl;
                dfs(x+1,cnt+1);
            }else{
                dfs(x+1,cnt);
            }
            vis[i]=false;
        }
    }
    return ;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        //if(c[i]!=0) m++;
    }
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}
