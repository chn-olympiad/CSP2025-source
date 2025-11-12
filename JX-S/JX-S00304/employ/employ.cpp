#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,m,c[25],p[25],tot,sum;
long long ans;
string a;
bool vis[25];
void print(){
    sum=tot=0;
    for(int i=1;i<=n;i++){
        if(a[i-1]=='1'&&c[p[i]]>tot){
            sum++;
        }
        else tot++;
    }
    if(sum>=m)ans++;
    ans%=N;
}
void dfs(int x){
    if(x==n+1){
        print();
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            p[x]=i;
            dfs(x+1);
            vis[i]=0;
        }
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>a;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    dfs(1);
    ans%=N;
    cout<<ans<<endl;
    return 0;
}
