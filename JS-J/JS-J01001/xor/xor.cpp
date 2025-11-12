#include <bits/stdc++.h>
using namespace std;
int n,k,a[500002],s[500002],ans;
bool B=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    B&=(k<=1);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]^a[i];
        B&=(a[i]<=1);
    }
    if(B){
        if(k==0){
            int l=1;
            for(int i=1;i<=n;i++){
                if(a[i]==0 || l<i&&a[i]==1){
                    ans++;
                    l=i+1;
                }
            }
        }else{
            for(int i=1;i<=n;i++){
                if(a[i]==1) ans++;
            }
        }
        printf("%d\n",ans);
        return 0;
    }
    int l=1;
    for(int i=1;i<=n;i++){
        for(int j=l;j<=i;j++){
            if((s[i]^s[j-1])==k){
                ans++;
                l=i+1;
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
