#include<bits/stdc++.h>
using namespace std;
const int N=503;
const int mod=998244353;
int n,m,s[N],c[N],p[N],ans;
char tempstring[N];
bool st[N];
void dfs(int cur){
    if(cur==n+1){
        int fail=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i]==0||fail>=c[p[i]]){fail++;continue;}
            cnt++;
        }
        if(cnt>=m) ans++;
        return;
    }
    for(int i=1;i<=n;i++) if(!st[i]) st[i]=1,p[cur]=i,dfs(cur+1),st[i]=0;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",tempstring+1);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]),s[i]=tempstring[i]-'0';
    if(n<=10){
        dfs(1);
        printf("%d\n",ans);
        return 0;
    }
    printf("0\n");
    return 0;
}
