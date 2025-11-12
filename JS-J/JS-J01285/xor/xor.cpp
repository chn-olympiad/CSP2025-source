#include<cstdio>
using namespace std;
FILE *fin,*fout;
const int N=500005;
int n,k,a[N],sum[N];
long long ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        sum[i]=sum[i-1]^a[i];
    }
    for(int l=1;l<=n;l++)
        for(int r=l;r<=n;r++)
            if(sum[r]^sum[l-1]==k){
                ans++;
                l=r+1;
                r=l;
            }
    printf("%lld",ans);
    return 0;
}
