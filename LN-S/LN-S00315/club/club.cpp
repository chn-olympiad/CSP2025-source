#include <bits/stdc++.h>
using namespace std;
int T,stud[3][100005],ans[6];
int muta1[73]={0,1,2,3,1,3,2,2,1,3,2,3,1,3,1,2,3,2,1,1,2,4,1,4,2,2,1,4,2,4,1,4,1,2,4,2,1,1,3,4,1,4,3,3,1,4,3,4,1,4,1,3,4,3,1,2,3,4,2,4,3,3,2,4,3,4,2,4,2,3,4,3,2};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    for (int i=1;i<=T;i++){
        memset(stud,0,sizeof(int)*100005*3);
        int n;
        scanf("%d",&n);
        for(int j=1;j<=n;j++){
            scanf("%d",&stud[1][j]);
            scanf("%d",&stud[2][j]);
            scanf("%d",&stud[3][j]);
        }
        if(n==2){
            int maxnn=0;
            for(int j=1;j<=3;j++){
                for(int k=1;k<=3;k++){
                    if(j!=k){
                        int tempv =stud[i][1]+stud[j][2];
                        if(tempv>maxnn) maxnn=tempv;
                    }
                }
            }
            ans[i]=maxnn;
        }else if(n==4){
            ans[i]=0;
            for(int j=1;j<=72;j+=3){
                int tempvv=0;
                for(int k=1;k<=3;k++){
                    tempvv+=stud[k][muta1[j+1]];
                }
                if(tempvv>ans[i]) ans[i]=tempvv;
            }
        }else{
            sort(&stud[1][1],&stud[1][n]);
            for(int j=n/2+1;j<=n;j++){
                ans[i]+=stud[1][j];
            }
        }
    }
    for (int i=1;i<=T;i++){
        printf("%d\n",ans[i]);
    }
}
