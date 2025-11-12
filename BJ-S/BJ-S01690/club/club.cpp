#include<bits/stdc++.h>
using namespace std;
int t,n,f[500001],g[4],p[500001],sum;
struct sj{
    int w,id;//id%3==0:c id%3==1:a id%3==2:b
}a[500001];
bool cmp(sj a,sj b){
    if(a.w!=b.w){
        return a.w>b.w;
    }
    return a.id<b.id;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        sum=0;
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        scanf("%d",&n);
        for(int i=1;i<=n*3;i+=3){
            scanf("%d%d%d",&a[i].w,&a[i+1].w,&a[i+2].w);
            a[i].id=i;
            a[i+1].id=i+1;
            a[i+2].id=i+2;
            p[(i-1)/3]=min({a[i].w,a[i+1].w,a[i+2].w});
            a[i].w-=p[(i-1)/3];
            a[i+1].w-=p[(i-1)/3];
            a[i+2].w-=p[(i-1)/3];
            //printf("%d %d %d,p=%d\n",a[i].w,a[i+1].w,a[i+2].w,p[(i-1)/3]);
        }
        sort(a+1,a+n*3+1,cmp);
        //printf("\n");
        //for(int i=1;i<=n*3;i+=3){
        //    printf("%d %d %d,p=%d\n",a[i].w,a[i+1].w,a[i+2].w,p[(i-1)/3]);
        //}
        for(int i=1;i<=n*3;i++){
            if((!f[(a[i].id-1)/3])&&(g[a[i].id%3]<n/2)){
                //printf("student %d choose %c\n",(a[i].id-1)/3,((a[i].id%3)==2?'b':((a[i].id%3)==1?'a':'c')));
                sum+=a[i].w+p[(a[i].id-1)/3];
                f[(a[i].id-1)/3]=1;
                g[a[i].id%3]++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
