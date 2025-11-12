#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],b[510],vis[510],ans[510],f,tim,kkk;
char c;
void dfs(int pos){
    if(pos==n+1){
        f=0;
        tim=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0||f>=b[ans[i]]){
                f++;
            }
            if(a[i]==1&&f<b[ans[i]]){
                tim++;
            }
        }
        if(tim>=m){kkk++; kkk%=998244353;}
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
        ans[pos]=i;
        vis[i]=1;
        dfs(pos+1);
        vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c;
        a[i]=c-'0';
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    dfs(1);
    cout<<kkk;
    return 0;
}
