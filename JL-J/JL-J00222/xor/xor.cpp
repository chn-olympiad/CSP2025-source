#include <bits/stdc++.h>
using namespace std;
int n,k,a[500050],cnt,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i=-~i) scanf("%d",&a[i]);
    if(k==1){
        for(int i=1;i<=n;i=-~i) if(a[i]==1) ans=-~ans;
    }
    else{
        for(int i=1;i<=n;i=-~i){
            if(a[i]==0) ans=-~ans;
            else if(i!=n) ans=-~ans,i=-~i;
        }
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
