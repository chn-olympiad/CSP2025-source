#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],cnt;
bool vis[510];
long long jcl[100000];
string s;
int jc(int n){
    if(n==0)return 1;
    if(jcl[n]>0)return jcl[n];
    int r=n*jc(n-1);
    r%=998244353;
    jcl[n]=r;
    return r;
}
void dfs(int pp,int failp){
    if(pp>=m){
        cnt+=jc(n-pp-failp);
        cnt%=998244353;
        return;
    }
    if(pp+failp==n)return;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        vis[i]=1;
        if(c[i]>failp&&s[pp+failp]=='1')dfs(pp+1,failp);
        else dfs(pp,failp+1);
        vis[i]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(n>99){
        int sum=0,z=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')sum++;
        }
        if(sum==0){
            cout<<jc(n);
            return 0;
        }
    }
    dfs(0,0);
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
