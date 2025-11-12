#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000;
int n,m;
int e[N],w[N],k[N],r[N];
ll x=0;
void dfs(int s,int lq){
    //if(n-lq<m) return;
    if(s==n+1){
        if(n-lq>=m) x++;
        //cout<<endl;
        //for(int i=1;i<=n;i++) cout<<r[i]<<" ";
        //cout<<endl;
    }
    for(int i=1;i<=n;i++){
        if(k[i]==0){
                //cout<<i<<" ";
                //r[s]=i;
            k[i]=1;
          dfs(s+1,lq);
            if(w[i]<=lq){
                dfs(s+1,lq+1);
            continue;
            }
            if(e[i]) dfs(s+1,lq);
            else dfs(s+1,lq+1);
            k[i]=0;
        }
        else continue;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>e[i];
    }
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    dfs(1,0);
    cout<<x;
    return 0;
}

