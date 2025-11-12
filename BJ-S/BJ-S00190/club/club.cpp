#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
    int a,b,c;
    int maxs;
    int la,lb,lc;
}p[N];
int n;
bool cmp1(node x,node y){
    if(x.la==y.la&&x.la==0){
        return max(x.lb,x.lc)>max(y.lb,y.lc);
    }
    return x.la>y.la;
}
bool cmp2(node x,node y){
    if(x.lb==y.lb&&x.lb==0){
        return x.lc>y.lc;
    }
    return x.lb>y.lb;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&p[i].a,&p[i].b,&p[i].c);
            p[i].maxs=max(p[i].a,max(p[i].b,p[i].c));
            ans+=p[i].maxs;
            p[i].la=p[i].a-p[i].maxs;
            p[i].lb=p[i].b-p[i].maxs;
            p[i].lc=p[i].c-p[i].maxs;
            //printf("%d %d %d\n",p[i].la,p[i].lb,p[i].lc);
        }
        int n1=0,n2=0,n3=0;
        for(int i=1;i<=n;i++){
            if(p[i].la==0) n1++;
            else if(p[i].lb==0) n2++;
            else if(p[i].lc==0) n3++;
        }
        if(n3>n/2&&n1<=n/2){
            swap(n1,n3);
            for(int i=1;i<=n;i++){
                swap(p[i].la,p[i].lc);
                swap(p[i].a,p[i].c);
            }
        }
        if(n2>n/2&&n1<=n/2){
            swap(n1,n2);
            for(int i=1;i<=n;i++){
                swap(p[i].la,p[i].lb);
                swap(p[i].a,p[i].b);
            }
        }
        sort(p+1,p+1+n,cmp1);
        int k=n1-n/2;
        //printf("%d\n",n1);
        n1-=k;
        for(int i=1;i<=k;i++){
            //printf("%d %d %d\n",p[i].la,p[i].lb,p[i].lc);
            if(p[i].lb>p[i].lc){
                ans+=p[i].lb;
                p[i].lc-=p[i].lb;
                p[i].lb=0;
                n2++;
            }
            else{
                ans+=p[i].lc;
                p[i].lb-=p[i].lc;
                p[i].lc=0;
                n3++;
            }
        }
        if(n3>n/2&&n2<=n/2){
            swap(n2,n3);
            for(int i=1;i<=n;i++){
                swap(p[i].lb,p[i].lc);
                swap(p[i].b,p[i].c);
            }
        }
        //printf("%d %d\n",n1,n2);
        sort(p+1,p+1+n,cmp2);
        k=n2-n/2;
        for(int i=1;i<=k;i++){
            //printf("%d %d %d\n",p[i].la,p[i].lb,p[i].lc);
            ans+=p[i].lc;
        }
        printf("%d\n",ans);
    }
    return 0;
}
