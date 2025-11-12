#include<bits/stdc++.h>
using namespace std;
int n,m,c[520],w,k,ans,d[520];
char s[520];
bool b[510];
void solve(int x){
    if(x==n+1){
        w=0,k=0;
        for(int i=1;i<=n;i++){
        if(s[i]=='0')
            w++;
        else
            if(d[i]<=w)
                w++;
            else
                k++;
        }
        if(k>=m)
            ans++,ans%=998244353;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!b[i]){
            b[i]=1;
            d[x]=c[i];
            solve(x+1);
            b[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d%s",&n,&m,s+1);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    solve(1);
    printf("%d",ans);
    return 0;
}

