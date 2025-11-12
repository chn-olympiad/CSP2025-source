#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>//5 - 10 pts code
struct cl{
    int num;
    int tag;
};
bool cmp(const int &x,const int &y){
    return x>y;
}
int T;
main(){
    freopen("club1.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    bool ai2andai3=true,ai3=true;
    while(T--){
        int n;//odd,n<=1e5
        scanf("%d",&n);
        int l=n/2;
        int a1[n+1];
        int a2[n+1];
        int a3[n+1];
        int ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a1[i]);
            scanf("%d",&a2[i]);
            scanf("%d",&a3[i]);
            if(a2[i]!=0){
                ai2andai3=false;
            }
            if(a3[i]!=0){
                ai2andai3=false;
                ai3=false;
            }else if(n==2){

            }
        }
        std::sort(a1+1,a1+n+1,cmp);

        if(ai2andai3){
            for(int i=1;i<=l;i++){
                //printf("a1: %d\n",a1[i]);
                ans+=a1[i];
            }
            printf("%d\n",ans);
        }else{
            std::sort(a2+1,a2+n+1,cmp);
            std::sort(a3+1,a3+n+1,cmp);
            ans+=a1[1]+a2[1]+a3[1];
            printf("%d\n",ans);
        }
    }
    //printf("\nTime : %d",clock());
}
