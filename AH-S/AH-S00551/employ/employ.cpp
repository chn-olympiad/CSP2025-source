#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,a[N],p[N],ans;
bool vis[N];
string s;
void dfs(int x,int cnt){
    if(x>n){
        if(cnt>=m){
            ans++;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            if(!(x-cnt-1>=a[i]||s[x]=='0')){
                dfs(x+1,cnt+1);
            }else{
                dfs(x+1,cnt);
            }
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
