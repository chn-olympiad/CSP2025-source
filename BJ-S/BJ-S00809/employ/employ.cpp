#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,A=1,ans,a[505],v[505],p[505],l;
string s;
void dfs(int k){
    if(k>n){
        int cnt=0;
        for(int i=1;i<=n;i++)if(cnt>=a[p[i]]||s[i-1]=='0')cnt++;
        if(n-cnt>=m)ans++;
        return;
    }
    for(int i=1;i<=n;i++)
        if(!v[i]){
            v[i]=1,p[k]=i;
            dfs(k+1);
            v[i]=0,p[k]=0;
        }
}
int main(){
    freopen("empoly.in","r",stdin);
    freopen("empoly.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1),cout<<ans;
}