#include<bits/stdc++.h>
namespace fzx{
    const int N=1e5+10;
    struct node1{
        int id,val;
    }a[N][10];
    struct node2{
        int cha,id1,id2,v1,v2;
    }b[N];
    bool cmp1(node1 x,node1 y){
        return x.val>y.val;
    }
    bool cmp2(node2 x,node2 y){
        if(x.cha==y.cha)return x.v1>y.v2;
        return x.cha>y.cha;
    }
    void main(){
        int n,sum1=0,sum2=0,sum3=0,res=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][1].val,&a[i][2].val,&a[i][3].val);
            a[i][1].id=1;
            a[i][2].id=2;
            a[i][3].id=3;
            std::sort(a[i]+1,a[i]+4,cmp1);
            b[i]={a[i][1].val-a[i][2].val,a[i][1].id,a[i][2].id,a[i][1].val,a[i][2].val};
        }
        std::sort(b+1,b+1+n,cmp2);
        for(int i=1;i<=n;i++){
            if(b[i].id1==1){
                if(sum1==n/2){
                    if(b[i].id2==2)sum2++;
                    else sum3++;
                    res+=b[i].v2;
                }else sum1++,res+=b[i].v1;
            }else if(b[i].id1==2){
                if(sum2==n/2){
                    if(b[i].id2==1)sum1++;
                    else sum3++;
                    res+=b[i].v2;
                }else sum2++,res+=b[i].v1;
            }else{
                if(sum3==n/2){
                    if(b[i].id2==1)sum1++;
                    else sum2++;
                    res+=b[i].v2;
                }else sum3++,res+=b[i].v1;
            }
        }
        printf("%d\n",res);
    }
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)fzx::main();
    return 0;
}