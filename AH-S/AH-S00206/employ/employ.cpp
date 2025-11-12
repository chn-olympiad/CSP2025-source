#include<bits/stdc++.h>
using namespace std;
int n,m,v[100001],ans,y[10001],t[10001];
bool flag[10001],l[10001];
char c;
bool pd(){
    int cnt=0,blu=0;
    for(int i=1;i<=n;i++){
        if(y[i]==y[i-1]&&blu<t[i]) cnt++;
        else blu++;
    }
    return cnt>=m;
}
void dfs(int x){
    if(x==n+1){
        if(pd()){
            ans++;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!l[i]){
            t[x]=v[i];
            l[i]=1;
            dfs(x+1);
            l[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c;
        if(c-'0'==0) y[i]=y[i-1]+1;
        else y[i]=y[i-1];
    }
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    dfs(1);
    cout<<ans%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
