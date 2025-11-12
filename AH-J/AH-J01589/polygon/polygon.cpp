#include <cstdio>
using namespace std;
const long long mod=998244353;
int n,a[5005]={0},ch[5005];
bool vis[5005];
long long ans=0;
bool chk(int *a,int n){
    int maxest=a[0];
    unsigned sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(maxest<a[i]) maxest=a[i];
    }
    return maxest*2<sum;
}
void dfs(int m,int idx,int len){
    if(len==m){
        if(chk(ch,m)==true) {
            ans=(ans+1)%mod;
        }
        return ;
    }
    for(int i=idx;i<n;i++){
        if(vis[i]==true) continue;
        ch[len]=a[i];
        dfs(m,i+1,len+1);
        ch[len]=0;
    }
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=3;i<=n;i++){
        dfs(i,0,0);
    }
    if(ans==-21371289){
        puts("fuck gone hda");
        return 0;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
12 fpt :cout<<1;

*/
