#include<bits/stdc++.h>
#define Maxn 5000+10
#define MOD 998244353
using namespace std;
int n,ans=0;
int a[Maxn];
void free(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
}
void dfs(int x,int y,int z,int g){
    if(x==y){
        for(int i=1;i<=n-x+1;i++){
            dfs(x,y-1,i,g+a[i]);
        }
    }
    else{
        if(y>1){
            for(int i=z+1;i<=n-y+1;i++){
                dfs(x,y-1,i,g+a[i]);
            }
        }
        else{
            for(int i=n;i>z;i--){
                if(a[i]<g){
                    ans+=i-z;
                    ans%=MOD;
                    return;
                }
            }
        }
    }
    return;
}
int main(){
    free();
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=3;i<=n;i++){
        dfs(i,i,0,0);
    }
    printf("%d",ans);
    return 0;
}
