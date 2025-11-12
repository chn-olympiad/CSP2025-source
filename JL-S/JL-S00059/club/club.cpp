#include <bits/stdc++.h>
using namespace std;
//struct Node{
//    int num;
//    int a;
//    int b;
//    int c;
//};

int f(int n,int inow,int **s,int *Hash){
    if(inow>=n){return 0;}
    //if(inow>0){
    //    dp[inow][H2[0]][H2[1]][H2[2]].a=dp[inow-1][H2[0]][H2[1]][H2[2]].a;
    //    dp[inow][H2[0]][H2[1]][H2[2]].b=dp[inow-1][H2[0]][H2[1]][H2[2]].b;
    //    dp[inow][H2[0]][H2[1]][H2[2]].c=dp[inow-1][H2[0]][H2[1]][H2[2]].c;
    //}
    //Node tmp1=dp[inow][H2[0]][H2[1]][H2[2]];
    //if(tmp1.num>0 && Hash[0]+tmp1.a<=n/2 && Hash[1]+tmp1.b<=n/2 && Hash[2]+tmp1.c<=n/2){return dp[inow][H2[0]][H2[1]][H2[2]].num;}
    int imax=0,pos=-1;
    //int x=H2[0],y=H2[1],z=H2[2];
    for(int i=0;i<=2;i++){
        if(Hash[i]<n/2){
            Hash[i]++;
            //if(Hash[i]>=n/2){H2[i]=0;}
            //if(i==0)dp[inow][H2[0]][H2[1]][H2[2]].a++;
            //if(i==1)dp[inow][H2[0]][H2[1]][H2[2]].b++;
            //if(i==2)dp[inow][H2[0]][H2[1]][H2[2]].c++;
            int tmp=f(n,inow+1,s,Hash)+s[inow][i];
            if(tmp>imax){
                pos=i;
                imax=tmp;
            }
            //if(i==0)dp[inow][H2[0]][H2[1]][H2[2]].a--;
            //if(i==1)dp[inow][H2[0]][H2[1]][H2[2]].b--;
            //if(i==2)dp[inow][H2[0]][H2[1]][H2[2]].c--;
            //imax=max(imax,f(n,inow+1,s,Hash,dp,H2)+s[inow][i]);
            Hash[i]--;
            //if(Hash[i]<n/2){H2[i]=1;}
        }
    }
    //if(pos==0)dp[inow][H2[0]][H2[1]][H2[2]].a++;
    //if(pos==1)dp[inow][H2[0]][H2[1]][H2[2]].b++;
    //if(pos==2)dp[inow][H2[0]][H2[1]][H2[2]].c++;
    //Hash[pos]++;
    //if(Hash[pos]>=n/2){H2[pos]=0;}
    //dp[inow][H2[0]][H2[1]][H2[2]]=imax;
    //dp[inow][x][y][z].num=imax;
    //printf("dp[%d][%d][%d][%d]=%d\n",inow,H2[0],H2[1],H2[2],imax);
    return imax;
}
int f2(int n,int **s){
    int re=0;
    int *ss=new int[n];
    for(int i=0;i<=n-1;i++){
        ss[i]=s[i][0];
    }
    //sort(ss,ss+n);
    for(int i=n/2;i<=n-1;i++){
        re+=ss[i];
    }

    return re;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,satis=0;
        scanf("%d",&n);
        int **s=new int*[n];
        int Hash[3]={0};
        int H2[3]={1,1,1};
        int ion=1;
        for(int i=0;i<=n-1;i++){
            s[i]=new int[3];
            for(int j=0;j<=2;j++){
                scanf("%d",&s[i][j]);
                if(s[i][1]>0 || s[i][2]>0){ion=0;}
            }
        }
     //   Node ****dp=new Node***[n];
    //    for(int i=0;i<=n-1;i++){
    //        dp[i]=new Node**[2];
    //        for(int j=0;j<=1;j++){
    //            dp[i][j]=new Node*[2];
    //            for(int k=0;k<=1;k++){
     //               dp[i][j][k]=new Node[2];
    //                dp[i][j][k][0].num=0;
    //                dp[i][j][k][1].num=0;
    //                dp[i][j][k][0].a=0;
    //                dp[i][j][k][1].a=0;
    //                dp[i][j][k][0].b=0;
    //                dp[i][j][k][1].b=0;
    //                dp[i][j][k][0].c=0;
    //                dp[i][j][k][1].c=0;
    //            }
    //        }


        //}
        if(ion){
            satis=f2(n,s);
            return 0;
        }
        satis=f(n,0,s,Hash);

        printf("%d\n",satis);
    }
    return 0;
}
//Ren5Jie4Di4Ling5%
