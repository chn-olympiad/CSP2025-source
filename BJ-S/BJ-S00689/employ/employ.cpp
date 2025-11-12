#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int n,m,cnt,tot,a[N],c[N];
bool flagA=true,vis[N];
string s;
void dfs(int x){
    if(x==n+1){
        int tot=0;
        for(int i=1;i<=n;i++){
            int x=a[i];
            if(s[i]=='1'&&i-1-tot<c[x])
                tot++;
        }
        if(tot>=m)
            cnt++;
        return;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]){
            vis[i]=true;
            a[x]=i;
            dfs(x+1);
            vis[i]=false;
            a[x]=0;
        }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s="#"+s;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=n;i++)
        if(s[i]=='1')
            tot++;
    if(tot<m){
        cout<<0<<'\n';
        return 0;
    }
    for(int i=1;i<=n;i++)
        if(s[i]!='1')
            flagA=false;
    
    if(n<=10){
        dfs(1);
        cout<<cnt<<'\n';
        return 0;
    }
    else if(m==1){
        int x;
        for(int i=1;i<=n;i++)
            if(s[i]=='1'){
                x=i;
                break;
            }
        for(int i=1;i<=n;i++)
            if(x-1<c[i])
                cnt++;
        cout<<cnt<<'\n';
        return 0;
    }
    // else if(m==n){

    // }
    // else if(flagA){

    // }
    return 0;
}