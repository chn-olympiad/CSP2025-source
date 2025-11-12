#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
char s[510];
bool p[510],f[520];
int no[510];
int n,m,c[510],ans,l[510];

void dfs(int k){
    if(k>n){
        int sum=n;
        int x=0;
        for(int i=1;i<=n;i++)
            if(no[++x]>=c[l[i]]){
                sum--;//x--;
            }

        if(sum>=m)ans++;
        ans%=mod;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!f[i]){
            f[i]=1;
            l[k]=i;
            dfs(k+1);
            f[i]=0;
            l[k]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)
        p[i]=s[i]-'0';
    no[0]=0;
    for(int i=1;i<=n;i++)
        no[i]=no[i-1]+p[i];
    dfs(1);
    printf("%d",ans);
}
