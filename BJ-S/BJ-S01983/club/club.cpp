#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int ans;
int numa,numb,numc;
struct wsw{
    int a,b,c;
}num[100005];
bool cmp_a(wsw x,wsw y){
    return x.a-max(x.b,x.c)<y.a-max(y.b,y.c);
}
bool cmp_b(wsw x,wsw y){
    return x.b-max(x.a,x.c)<y.b-max(y.a,y.c);
}
bool cmp_c(wsw x,wsw y){
    return x.c-max(x.a,x.b)<y.c-max(y.a,y.b);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        ans=0;
        numa=0;
        numb=0;
        numc=0;
        scanf("%d",&n);
        for(int j=1;j<=n;j++){
            scanf("%d%d%d",&num[j].a,&num[j].b,&num[j].c);
            if(num[j].a>=max(num[j].b,num[j].c)) numa++;
            else if(num[j].b>=max(num[j].a,num[j].c)) numb++;
            else numc++;
            ans+=max(num[j].a,max(num[j].b,num[j].c));
        }
        if(numa>n/2){
            sort(num+1,num+n+1,cmp_a);
            ans=0;
            for(int j=1;j<=n/2;j++){
                ans+=max(num[j].b,num[j].c);
            }for(int j=n/2+1;j<=n;j++){
                ans+=num[j].a;
            }
        }else if(numb>n/2){
            sort(num+1,num+n+1,cmp_b);
            ans=0;
            for(int j=1;j<=n/2;j++){
                ans+=max(num[j].a,num[j].c);
            }for(int j=n/2+1;j<=n;j++){
                ans+=num[j].b;
            }
        }else if(numc>n/2){
            sort(num+1,num+n+1,cmp_c);
            ans=0;
            for(int j=1;j<=n/2;j++){
                ans+=max(num[j].a,num[j].b);
            }for(int j=n/2+1;j<=n;j++){
                ans+=num[j].c;
            }
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}