#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e5+5;
int n,k,a[N],cnt,ans=1;
struct qj{
    int l,r;
}q[N];
bool cmp(qj x,qj y){
    return x.r<y.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=i;j<=n;j++){
            sum=sum^a[j];
            if(sum==k){
                q[++cnt]={i,j};
                break;
            }
        }
    }
    if(cnt==0){
        printf("0");
        return 0;
    }
    sort(q+1,q+cnt+1,cmp);
    int R=q[1].r;
    for(int i=2;i<=cnt;i++){
        if(q[i].l>R){
            ans++;
            R=q[i].r;
        }
    }
    printf("%d",ans);
    return 0;
}

