#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5010],ans,cnt;
inline void dfs(int p,int num,int tot){
    if(num==1){
        int l=p,r=n;
        while(l<=r){
            int mid=(l+r)>>1;
            if(a[mid]<tot) l=mid+1;
            else r=mid-1;
        }
        if(r>p&&r<=n) ans=(ans+r-p)%mod;
        return;
    }
    else for(int i=p+1;i<=n-num+1;i=-~i) dfs(i,num-1,tot+a[i]);
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i=-~i) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=2;i<n;i=-~i){
        for(int j=1;j<=n-i;j=-~j){
            dfs(j,i,a[j]);
        }
    }
    printf("%d",ans%mod);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
