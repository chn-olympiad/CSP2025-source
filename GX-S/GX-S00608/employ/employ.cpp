#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[510],ans,c[510],k[510];
string s;
bool b[510];
inline void dfs(int i,int x){
    if(i==n+1){
        if(n-x>=m){
            /*for(int j=1;j<=n;j++)
                printf("%d ",c[j]);
            for(int j=1;j<=n;j++)
                printf("%d ",k[j]);

            printf("\n%d\n",n-x);*/
            ans++;
            ans%=mod;
        }
        return;
    }
    for(int j=1;j<=n;j++){
        if(b[j]) continue;
        c[i]=j;
        if(s[i-1]=='0'||x>=a[j]){
            b[j]=true;
            k[i]=x+1;
            dfs(i+1,x+1);
            b[j]=false;
        }else{
            b[j]=true;
            k[i]=x;
            dfs(i+1,x);
            b[j]=false;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>s;
    ans=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}
