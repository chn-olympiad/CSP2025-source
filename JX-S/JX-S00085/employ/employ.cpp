#include<bits/stdc++.h>
using namespace std;
bool vis[500];
long long n,m,ans,c[505];
string s;
void dfs(int z,int x,int y){
    if(z==0){
        if(x<=0){
            ans++;
            ans%=998244353;
            return;
        }
    }

    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i]=1;
            if(c[i]>y&&s[n-z]=='1')dfs(z-1,x-1,y);
            else dfs(z-1,x,y+1);
            vis[i]=0;
        }
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    dfs(n,m,0);
    cout<<ans;
    return 0;
}
