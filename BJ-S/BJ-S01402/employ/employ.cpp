#include<iostream>
using namespace std;

const int MAXN=5e2+5;
int n,m,ans,c[MAXN];
char s[MAXN];

int plan[MAXN];
bool vis[MAXN];
void dfs(int x){
    if(x==n+1){
        int lst=0;
        for(int i=1;i<=n;i++){
            if(lst>=c[plan[i]]){
                lst++;
                continue;
            }
            if(s[i]=='0')
                lst++;
        }
        if(lst<=n-m)ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        plan[x]=i,vis[i]=true;
        dfs(x+1);
        vis[i]=false;
    }
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    if(n<=10)dfs(1),cout<<ans<<endl;
    return 0;
}