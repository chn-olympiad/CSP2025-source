#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,mod=998244353;
int n,m;
char s[N];
bool is[N];
int c[N];
int ans=0;
void dfs(int x,int f,int g,int now){
    if(now!=-1){
     if(c[x]<=f||s[now]=='0'){
        f++;
     }
        else g++;
    }
    if(now==n-1){
 //       cout<<g<<" "<<f<<" "<<m<<endl;
        if(g>=m){
            ans=(ans+1)%mod;
        }
    }
    for(int i=1;i<=n;i++){
        if(!is[i]){
            is[i]=true;
            dfs(i,f,g,now+1);
            is[i]=false;
        }
    }
    return ;
}
void subtask1(){
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    dfs(-1,0,0,-1);
    cout<<ans<<endl;
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    if(n<=10) subtask1();
    fclose(stdin);
    fclose(stdout);
    return 0;
}


