#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int l[N],n,f[N],ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&l[i]);
    }
    sort(l+1,l+n+1);
    for(int i=1;i<=n;i++)f[i]=f[i-1]+l[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<i-1;j++){
            for(int k=i-1;k>1;k--){
                if(f[k]-f[j-1]>l[i])ans+=2*j;
                else break;
            }
        }
    }
    cout<<ans/2;
    return 0;
}
