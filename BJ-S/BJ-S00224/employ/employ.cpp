#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
int n,m;
bool v[505];
int c[505];
int vis[505];
long long ans;
void DFS(int x,int ac,int unac){
    //cout<<x<<" "<<ac<<" "<<unac<<endl;
    if(x==n+1){
        if(ac>=m) ans++,ans%=M;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            if(unac>=c[i] || v[i]==0) vis[i]=x+10,DFS(x+1,ac,unac+1);
            else vis[i]=x,DFS(x+1,ac+1,unac);
            vis[i]=false;
        }
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    char ch;
    for(int i=1;i<=n;i++){
        cin>>ch;
        v[i]=ch-'0';
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    DFS(1,0,0);
    cout<<ans%M<<endl;
    return 0;
}
