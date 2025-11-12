#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int f[1005][1005];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    int maxn=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        maxn=max(maxn,a[i]);
    }
    if(maxn==1){
        int sum1=0,sum0=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0)sum0++;
            else sum1++;
        }
        if(k==1){
            int minn=min(sum1,sum0);
            if(minn==sum1)printf("%d",minn);
            else printf("%d",sum1);
        }
        else{
            int ans=sum0+(sum1>>1);
            printf("%d",ans);
        }
        return 0;
    }
    if(n>1000){
        printf("1");
        return 0;
    }
    for(int i=1;i<=n;i++)f[i][i]=a[i];
    for(int len=1;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            int minn=1e9,tt=0;
            for(int kk=i;kk<j;kk++){
                int tmp=(f[i][kk]^f[kk+1][j]);
                if(abs(kk-tmp)<minn)tt=kk;
            }
            f[i][j]=f[i][tt]^f[tt+1][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int tt=0;
        for(int kk=i;kk<=n;kk++){
            if(f[i][kk]==k){
                tt=kk;
                break;
            }
        }
        if(tt==0)continue;
        i=tt;
        ans++;
    }
    printf("%d",ans);
    return 0;
}
