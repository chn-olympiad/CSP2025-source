#include <bits/stdc++.h>
using namespace std;
const int P=998244353;
char s[505];
int n,m,a[505],c[505];
bool b[505];
long long ans=0;
inline void dfs(int x){
    if(x==n+1){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='1'&&i-cnt-1<a[c[i]]){
                cnt++;
            }
        }
        ans+=(cnt>=m);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!b[i]){
            b[i]=true;
            c[x]=i;
            dfs(x+1);
            b[i]=false;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d%s",&n,&m,s+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dfs(1);
    cout<<ans%P;

    return 0;
}
