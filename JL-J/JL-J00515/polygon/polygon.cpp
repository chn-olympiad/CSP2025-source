#include<bits/stdc++.h>
#define mod 998244353
#define maxn 5010
using namespace std;
int a[maxn];
int ans,n,lensum,lenmax;
void dfs(int x,int deep){
    if(a[x]>lenmax){
        lenmax=a[x];
    }
    lensum+=a[x];
    if(deep>=3&&lensum>2*lenmax){
        ans++;
    }
    int tend1=lensum;
    int tend2=lenmax;
    for(int i=x+1;i<=n;i++){
        dfs(i,deep+1);
        lensum=tend1;
        lenmax=tend2;
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dfs(0,0);
    ans%=mod;
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
