#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500002];
int sum[500002];
int ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(i!=1)
            sum[i]=sum[i-1]^a[i];
        else    
            sum[1]=a[1];
    }
    sum[0]=~a[1];
    int lst=1;
    if(a[1]==k){
        ans++;
        lst++;
    }
    for(int i=2;i<=n;i++){
        for(int j=lst;j<=i;j++){
            if((sum[i]^sum[j-1])==k||(j-1==0&&sum[i]==k)){
                ans++;
                lst=i+1;
                break;
            }
        }
    }
    printf("%d",ans);
    return 0;
}