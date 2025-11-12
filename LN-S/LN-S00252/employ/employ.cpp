#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int mod=998244353;
int n,m;
char s[510];
int c[510];
bool used[510];
int ans;
int maxsuc;
void dfs(int ind,int fail){
    if(fail>n-m){
        return;
    }
    if(ind==n){
        ans=(ans+1)%mod;
        return;
    }
    printf("%d",ind);
    for(int i=1;i<=n;i++){
        if(!used[i]){
            used[i]=1;
            dfs(ind+1,(s[ind]=='0' || c[i]<=fail?fail+1:fail));
            used[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    for(int i=0;i<n;i++){
        maxsuc+=s[i]-'0';
    }
    if(maxsuc<m){
        cout<<0;
        return 0;
    }
    dfs(0,0);
    printf("%d",ans);
    return 0;
}
