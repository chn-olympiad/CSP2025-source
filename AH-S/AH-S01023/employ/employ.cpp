#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353;
int n,m,a[505],ans;
bool vis[30];
int b[30];
int test=1;
int f[505];
string s;
void dfs(int t){
    if(t==n+1){
        int cnt=0,c=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0'||cnt>=a[b[i]])cnt++;
            else c++;
        }
        if(c>=m)ans++;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            b[t]=i;
            vis[i]=true;
            dfs(t+1);
            vis[i]=false;
        }
    }
}
void solveA(){
    ans=1;
    for(int i=1;i<=n;i++){
        ans=(ans*i)%P;
        if(a[i]==0||s[i]=='0'){
            cout<<0<<endl;
            exit(0);
        }
    }
    cout<<ans<<endl;
    exit(0);
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    s='#'+s;
    for(int i=1;i<=n;i++){
        if(s[i]=='0'){
            test=0;
            break;
        }
    }
    //if(test)solveB();
    if(n==m)solveA();
    dfs(1);
    cout<<ans%P<<endl;
    return 0;
}
//Ren5Jie4Di4Ling5%
