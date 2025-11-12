#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],p[N];
bool v[N];
int ans;
string s;
void check(){
    int cnt=0,res=0;
    for(int i=1;i<=n;i++){
        if(c[p[i]]<=cnt||s[i]=='0')
            cnt++;
        else{
            res++;
            cnt=0;
        }
    }
    if(res>=m) ans++;
}
void dfs(int now){
    if(now==n+1){
        check();
        return;
    }
    for(int i=1;i<=n;i++){
        if(!v[i]){
            p[now]=i;
            v[i]=1;
            dfs(now+1);
            v[i]=0;
            p[now]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;s=" "+s;
    for(int i=1;i<=n;i++) cin>>c[i];
    dfs(1);
    cout<<ans;
    return 0;
}
