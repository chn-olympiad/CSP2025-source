#include <iostream>
using namespace std;
long long q=998244353,ans;
int n,vis[100001],m,c[1000001];
string s;
void dfs(int sum,int len){
    int w=0;
    for(int i=1;i<=n;i++){
        if(len==n){
            if(n-sum>=m){
                ans++;
                ans%=q;
            }
            return;
        }
    }
    for(int j=1;j<=n;j++){
        if(vis[j]==0){
            vis[j]=1;
            if(c[j]<=sum||s[len]=='0') dfs(sum+1,len+1);
            else dfs(sum,len+1);
            vis[j]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    int is=0;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]!=1) is=1;
    }
    if(is==0){
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=q;
        }
        cout<<ans;
    }
    else{
        dfs(0,0);
        cout<<ans;
    }
    return 0;
}
