#include<bits/stdc++.h>
#define ll long long
const int p=998244353;
int n,m,c[505];
char s[505];
bool fl[505];
int a[505];
ll ans=0;
bool check(){
    int sum=0;
    for(int i=1;i<=n;i++){
        if(sum>=c[a[i]])sum++;
        else if(s[i]=='0')sum++;
    }
    return n-sum>=m;
}
void dfs(int depth=1){
    if(depth==n+1){
        if(check()){
            ans++;
            ans%=p;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(fl[i]==0){
            fl[i]=1;
            a[depth]=i;
            dfs(depth+1);
            fl[i]=0;
        }
    }
    return ;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)scanf("%d",c+i);
    dfs();
    printf("%d",ans);
}
