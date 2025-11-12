#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=505,P=998244353;
string t;
int s[N],c[N];
int p[N]; bool used[N];
int ans;
bool check(){
    int cnt=0,sum=0;
    for(int i=1;i<=n;i++){
        if(c[p[i]]>sum&&t[i]=='1') cnt++;
        else sum++;
    }
    return cnt>=m;
}
void dfs(int x){
    if(x>n){
        if(check()) ans++,ans%=P;
        return ;
    }
    for(int i=1;i<=n;i++)
        if(!used[i]){
            p[x]=i;
            used[i]=true;
            dfs(x+1);
            p[x]=0;
            used[i]=false;
        }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m; cin>>t; t=" "+t;
    for(int i=1;i<=n;i++)
        cin>>c[i],s[i]=s[i-1]+t[i]-'0';
    sort(c+1,c+n+1);
    dfs(1);
    cout<<ans;
    return 0;
}
