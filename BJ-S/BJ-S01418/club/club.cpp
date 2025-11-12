#include<bits/stdc++.h>
using namespace std;
struct BM{
    int name,cj;
}bm[100005];
bool cmp(BM a,BM b){
    return a.cj>b.cj;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int us[100005]={};

    int t,n=0,a[100005][4]={},m=0;
    long long ans=0;
    int be[100005]={},ne[100005]={},la[100005]={};
    int bes[4]={},bmrs=0;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        for(int i=1;i<=n;i++) us[i]=0;

        ans=0,bes[1]=0,bes[2]=0,bes[3]=0,m=0,bmrs=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
            if(a[i][1]>=a[i][2]){
                if(a[i][2]>=a[i][3]){
                    be[i]=1,ne[i]=2,la[i]=3;
                }else if(a[i][1]>=a[i][3]){
                    be[i]=1,ne[i]=3,la[i]=2;
                }else{
                    be[i]=3,ne[i]=1,la[i]=2;
                }
            }else{
                if(a[i][1]>=a[i][3]){
                    be[i]=2,ne[i]=1,la[i]=3;
                }else if(a[i][2]>=a[i][3]){
                    be[i]=2,ne[i]=3,la[i]=1;
                }else{
                    be[i]=3,ne[i]=2,la[i]=1;
                }
            }
            bes[be[i]]++;
        }
        for(int i=1;i<=3;i++){
            if(bes[i]>n/2) m=i;
        }
        if(!m){
            for(int i=1;i<=n;i++){
                ans+=a[i][be[i]];
            }
            printf("%lld\n",ans);
            continue;
        }
        for(int i=1;i<=n;i++){
            if(be[i]!=m){
                ans+=a[i][be[i]];

                //printf("%d +",a[i][be[i]]);
                //us[i]=be[i];
            }else{
                bm[++bmrs].name=i;
                bm[bmrs].cj=a[i][be[i]]-a[i][ne[i]];
            }
        }
        sort(bm+1,bm+bmrs+1,cmp);
        for(int i=1;i<=n/2;i++){
            ans+=a[bm[i].name][be[bm[i].name]];

           // printf("%d +",a[bm[i].name][be[i]]);
          //  us[bm[i].name]=be[i];
        }
        for(int i=(n/2)+1;i<=bmrs;i++){
            ans+=a[bm[i].name][ne[bm[i].name]];

        //    printf("%d +",a[bm[i].name][ne[i]]);
         //   us[bm[i].name]=ne[i];
        }
        printf("%lld\n",ans);

      //  printf("=%lld\n",ans);
       // printf("BM: ");
     //   for(int i=1;i<=bmrs;i++){
     //       printf("%d ",bm[i].name);
    //    }
    //    printf("  MAX: %d",m);
     //   printf("\nUS:  ");
    //    for(int i=1;i<=n;i++){
    //        printf("%d:%d  ",i,us[i]);
     //   }
      //  printf("\nBE:  ");
      //  for(int i=1;i<=n;i++){
     //       printf("%d:%d  ",i,be[i]);
     //   }
      //  printf("\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
