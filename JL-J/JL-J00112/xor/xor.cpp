#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],lst[N];
int dp[N];
int n,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    memset(lst,-1,sizeof(lst));
    scanf("%d%d",&n,&k);
    bool flag=1,cnt=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]>1){
            flag=0;
        }
        cnt+=(a[i]==1);
    }
    if(flag){
        if(k!=0 && k!=1){
            printf("0\n");
            return 0;
        }
        if(k==1){
            printf("%d\n",cnt);
            return 0;
        }
        else{
            cnt=0;
            int sum=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    sum+=cnt/2;
                    cnt=0;
                    sum++;
                }
                else{
                    cnt++;
                }
            }
            sum+=cnt/2;
            printf("%d\n",sum);
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        int x=0;
        for(int j=i;j>=1;j--){
            x^=a[j];
            if(x==k){
                lst[i]=j;
                break;
            }
        }
    }
    int mx=0;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        if(lst[i]!=-1){
            dp[i]=max(dp[i],dp[lst[i]-1]+1);
        }
        mx=max(mx,dp[i]);
    }
    printf("%d\n",mx);
    return 0;
}
/*
if a^b==c
    b^c==a
    b^a==c
    c^a==b
*/
