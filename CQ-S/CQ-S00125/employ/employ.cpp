#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=15;
int n,m,a[N],p[N],ans;char s[N];bool f[N];
void dfs(int x){
    if(x==n+1){
        int sum=0;
        for(int i=1,S=0;i<=n;i++){
            if(s[i]=='0'||S>=a[p[i]]) S++;
            else sum++;
        }
        if(sum>=m) ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(f[i]) continue;
        f[i]=1,p[x]=i,dfs(x+1),f[i]=0;
    }
}
int main(){//10pts(?)
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d %s",&n,&m,s+1);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    dfs(1);
    printf("%d",ans);
    return 0;
}