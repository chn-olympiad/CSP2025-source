#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int dp[N][3];
int times[3];
int mxx=INT_MIN;
struct node{
    int m1,m2,m3;
}a[N];
void dfs(int n,int x,int no,int no1,int no2,int no3){
    if(x==n+1){
        mxx=max(no,mxx);
        return ;
    }
    for(int i=0;i<3;i++){
        if(i==0){
            if(no1!=n/2){
                dfs(n,x+1,no+a[x].m1,no1+1,no2,no3);
            }
        }
        if(i==1){
            if(no2!=n/2){
                dfs(n,x+1,no+a[x].m2,no1,no2+1,no3);
            }
        }
        if(i==2){
            if(no3!=n/2){
                dfs(n,x+1,no+a[x].m3,no1,no2,no3+1);
            }
        }
    }
}
bool whatcount(int big,int big2,int ren1,int ren2){
    if(ren1<ren2) return 1;
    else return big<big2;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int ren1=0,ren2=0,ren3=0,bigs1=0,bigs2=0,bigs3=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].m1,&a[i].m2,&a[i].m3);
            ren1+=a[i].m1,ren2+=a[i].m2,ren3+=a[i].m3;
            int rec=max(a[i].m1,max(a[i].m2,a[i].m3));
            if(rec==a[i].m1) bigs1++;
            if(rec==a[i].m2) bigs2++;
            if(rec==a[i].m3) bigs3++;
        }
        mxx=INT_MIN;
        memset(times,0,sizeof(times));
        memset(dp,0,sizeof(dp));
        if(n<=10){
            dfs(n,1,0,0,0,0);
            printf("%d\n",mxx);
            continue;
        }
        else{
            dp[1][0]=a[1].m1,dp[1][1]=a[1].m2,dp[1][2]=a[1].m3;
            ren1-=a[1].m1,ren2-=a[1].m2,ren3-=a[1].m3;
            int mec=max(a[1].m1,max(a[1].m2,a[1].m3));
                    if(mec==a[1].m1) bigs1--;
                    if(mec==a[1].m2) bigs2--;
                    if(mec==a[1].m3) bigs3--;
                    if((a[1].m1==a[1].m2)&&(a[1].m2==a[1].m3)&&(a[1].m3==mec)){
                        if(whatcount(bigs1,bigs2,ren1,ren2)&&whatcount(bigs1,bigs3,ren1,ren3)) times[0]++;
                        else if(whatcount(bigs2,bigs1,ren2,ren1)&&whatcount(bigs2,bigs3,ren2,ren3)) times[1]++;
                        else times[2]++;
                    }
                    else if((a[1].m1==a[1].m3)&&(a[1].m3==mec)){
                        if(whatcount(bigs1,bigs3,ren1,ren3)) times[0]++;
                        else times[2]++;
                    }
                    else if((a[1].m1==a[1].m2)&&(a[1].m2==mec)){
                        if(whatcount(bigs1,bigs2,ren1,ren2)) times[0]++;
                        else times[1]++;
                    }
                    else if((a[1].m2==a[1].m3)&&(a[1].m3==mec)){
                        if(whatcount(bigs2,bigs2,ren1,ren3)) times[1]++;
                        else times[2]++;
                    }
                    else if(mec==a[1].m1) times[0]++;
                    else if(mec==a[1].m2) times[1]++;
                    else if(mec==a[1].m3) times[2]++;
            for(int i=2;i<=n;i++){
                for(int j=0;j<=2;j++){
                    if(times[j]>=(n/2)){
                        dp[i][j]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
                        continue;
                    }
                    int ai;
                    if(j==0) ai=a[i].m1;
                    else if(j==1) ai=a[i].m2;
                    else ai=a[i].m3;
                    dp[i][j]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]))+ai;
                }
                ren1-=a[i].m1;
                ren2-=a[i].m2;
                ren3-=a[i].m3;
                int mec=max(a[i].m1,max(a[i].m2,a[i].m3));
                    if(mec==a[i].m1) bigs1--;
                    if(mec==a[i].m2) bigs2--;
                    if(mec==a[i].m3) bigs3--;
                    if((a[i].m1==a[i].m2)&&(a[i].m2==a[i].m3)&&(a[i].m3==mec)){
                        if(whatcount(bigs1,bigs2,ren1,ren2)&&whatcount(bigs1,bigs3,ren1,ren3)) times[0]++;
                        else if(whatcount(bigs2,bigs1,ren2,ren1)&&whatcount(bigs2,bigs3,ren2,ren3)) times[1]++;
                        else times[2]++;
                    }
                    else if((a[i].m1==a[i].m3)&&(a[i].m3==mec)){
                        if(whatcount(bigs1,bigs3,ren1,ren3)) times[0]++;
                        else times[2]++;
                    }
                    else if((a[i].m1==a[i].m2)&&(a[i].m2==mec)){
                        if(whatcount(bigs1,bigs2,ren1,ren2)) times[0]++;
                        else times[1]++;
                    }
                    else if((a[i].m2==a[i].m3)&&(a[i].m3==mec)){
                        if(whatcount(bigs2,bigs2,ren1,ren3)) times[1]++;
                        else times[2]++;
                    }
                    else if(mec==a[i].m1) times[0]++;
                    else if(mec==a[i].m2) times[1]++;
                    else if(mec==a[i].m3) times[2]++;
            }
        }
        printf("%d\n",max(dp[n][0],max(dp[n][1],dp[n][2])));
    }
    return 0;
}
