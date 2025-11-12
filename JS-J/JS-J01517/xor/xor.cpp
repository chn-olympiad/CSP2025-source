#include<bits/stdc++.h>
using namespace std;
int n,k,x,sum,l=0,ans,ma;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ma=max(ma,a[i]);
    }
    if(ma==1&&k==1){
        int cnt=0;
        for(int i=1;i<=n;i++)cnt+=a[i];
        printf("%d",cnt);
        return 0;
    }
    for(int i=1;i<=n;i++){
        sum=0;
        bool b=0;
        int j;
        for(j=i;j>l;j--){
            sum^=a[j];
            if(sum==k){
                b=1;
                break;
            }
        }
        if(b){
            l=i;
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
