#include<bits/stdc++.h>
#define int long long
#define maxn ( 500 +5)
using namespace std;
//吾日三省吾身：freopen删注释了乎？大样例测了乎？暴力打了乎？
//please open use UTF-8
int n,m,c[maxn],vis[maxn],ans;
const int modn=998244353;
string str;
int loser=0;
void dfs(int num,int x){
    bool flag=(str[x]=='1' && loser<c[x]);
    //cout << flag << endl;
    if(!flag)loser++;
    if(num+flag==m){
        ans=(ans+1)%modn;return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        vis[i]=1;
        //cout << num+flag << endl;
        dfs(num+flag,i);
        vis[i]=0;
    }
    if(!flag)loser--;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m >> str;
    str='1'+str;
    for(int i=1;i<=n;i++){
        cin >> c[i];
        vis[i]=0;
    }
    c[0]=1;
    for(int i=1;i<=n;i++){
        vis[i]=1;
        dfs(0,i);
        vis[i]=0;
    }
    cout << ans;
    return 0;
}