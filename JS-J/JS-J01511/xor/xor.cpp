#include<cstdio>
using namespace std;
const int maxn=5e5+10;
int n,ind=0,k;
long long sum[maxn],a,ans=1;
struct qu{
    int l,r;
}c[maxn];
bool flag;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    sum[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        sum[i]=sum[i-1]^a;
    }
    for(int i=1;i<=n;i++){
        flag=0;
        for(int j=i;j>=1;j--){
            int v=sum[j-1] ^ sum[i];
            if(v==k){
                c[ind].l=j;
                c[ind].r=i;
                ind++;
                flag=1;
            }
            if(flag)break;
        }
    }
    int cur_end=c[0].r;
    for(int i=1;i<ind;i++){
        if(c[i].l>cur_end){
            ans++;
            cur_end=c[i].r;
        }
    }
    if(ind==0)printf(0);
    else printf("%d",ans);
    return 0;
}
