#include <bits/stdc++.h>
using namespace std;

struct node{
    int id;//即第几个输入的
    int a,b,c,ak,bk,ck;//即不选最大 会少多少满意度
    int st1,nd2,rd3;//三个部门满意度排序 2nd和3rd
}p[100010];

int picka[100010],pickb[100010],pickc[100010];
int dp[100010][5];

bool cmp1 (int i,int j){
    return max(p[i].bk,p[i].ck)>max(p[j].bk,p[j].ck);
}
bool cmp2 (int i,int j){
    return max(p[i].ak,p[i].ck)>max(p[j].ak,p[j].ck);
}
 bool cmp3 (int i,int j){
//     printf("compare %d to %d, ",i,j);
//     if(min(p[i].ak,p[i].bk)>min(p[j].ak,p[j].bk)) printf("%d nicer\n",i);
//     else printf("%d nicer\n",j);
    return max(p[i].ak,p[i].bk)>max(p[j].ak,p[j].bk);
}

int main (){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){

        int n;
        scanf("%d",&n);
        int maxn=n/2,sum=0;//sum即都选最大的结果
        int pa=0,pb=0,pc=0;//即全选最大时 每个社团总共的人数
        
        for(int i=1;i<=n;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            p[i].a=x,p[i].b=y,p[i].c=z;
            int m=max(x,max(y,z));
            p[i].ak=x-m,p[i].bk=y-m,p[i].ck=z-m;
            sum+=m;

            if(m==x){
                p[i].st1=1;
                if(y>z) p[i].nd2=2,p[i].rd3=3;
                else p[i].nd2=3,p[i].rd3=2;
                picka[++pa]=i;
            }else if(m==y){
                p[i].st1=2;
                if(x>z) p[i].nd2=1,p[i].rd3=3;
                else p[i].nd2=3,p[i].rd3=1;
                pickb[++pb]=i;
            }else{
                p[i].st1=3;
                if(x>y) p[i].nd2=1,p[i].rd3=2;
                else p[i].nd2=2,p[i].rd3=1;
                pickc[++pc]=i;
            }
//            printf("i=%d ak=%d bk=%d ck=%d\n",i,p[i].ak,p[i].bk,p[i].ck);
        }

//        printf("picka= %d pickb= %d pickc= %d\n",pa,pb,pc);
//        printf("maxn= %d sum= %d\n",maxn,sum);

        if(pa>maxn){//a部门不满足
//            printf("go 1--\n");
            sort(picka+1,picka+pa+1,cmp1);
            //现在越往前改变代价越小
//            for(int i=1;i<=pa;i++) printf("%d ",picka[i]);
//            printf("\n");
            for(int i=1;i<=pa-maxn;i++){
                if(p[picka[i]].nd2==2){
                    pb++;
                    sum+=p[picka[i]].bk;
                }else{
                    pc++;
                    sum+=p[picka[i]].ck;
                }
            }
        }
        if(pb>maxn){//b部门不满足
//            printf("go 2--\n");
            sort(pickb+1,pickb+pb+1,cmp2);
            //现在越往前改变代价越小
//            for(int i=1;i<=pb;i++) printf("%d ",pickb[i]);
//            printf("\n");
            for(int i=1;i<=pb-maxn;i++){
                if(p[pickb[i]].nd2==1){
                    pa++;
                    sum+=p[pickb[i]].ak;
                }else{
                    pc++;
                    sum+=p[pickb[i]].ck;
                }
            }
        }
        if(pc>maxn){//c部门不满足
//            printf("go 3--\n");
            sort(pickc+1,pickc+pc+1,cmp3);
            //现在越往前改变代价越小
//            for(int i=1;i<=pc;i++) printf("%d ",pickc[i]);
//            printf("\n");
            for(int i=1;i<=pc-maxn;i++){
                if(p[pickc[i]].nd2==1){
                    pa++;
                    sum+=p[pickc[i]].ak;
                }else{
                    pb++;
                    sum+=p[pickc[i]].bk;
                }
            }
        }
//        printf("end picka= %d pickb= %d pickc= %d\n",pa,pb,pc);
        printf("%d\n",sum);

    }
    return 0;
}

/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0

1 10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
ans:147325

*/


//大约是DP
//状态：dp[i][j]表示第j个部门截至到第i个成员的最大满意度
//一个成员只能去1或2或3 只需要挨个找这三个即可
//若没有人数限制，直接贪心找最大即可
//是否可以贪心？
//全部选最大再改变志愿
//似乎可证不会反复修改 YES！！！！！！！！

//转移：dp[i][j]=max(dp[i-1][j]+a[i].j)