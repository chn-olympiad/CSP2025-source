#include<iostream>
#include<cstdio>
using namespace std;
int t;
int cmp1(int x,int y,int z){
    if(x>y){
        if(x>z) return 1;
        else if(x<z) return 3;
    }
    else if(x<y){
        if(y>z) return 2;
        else if(y<z) return 3;
    }
}
int cmp2(int x,int y,int z){
    if(x>y){
        if(x>z)
            if(y>z) return 2;
            else return 3;
        else if(x<z) return 1;
    }
    else{
        if(y>z)
            if(x<z) return 3;
            else return 1;
        else if(z>y)  return 2;
    }
}

int cmp3(int x,int y,int z){
    if(x<y){
        if(x<z) return 1;
        else return 3;
    }
    else{
        if(y<z) return 2;
        else return 3;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n=0;
        int arr[100010][5]={{}};
        int dp[100010]={};
        int b[5]={};
        scanf("%d",&n);
        for(int j=1;j<=n;j++)
            scanf("%d%d%d",&arr[j][1],&arr[j][2],&arr[j][3]);
        b[1]=1,b[2]=1,b[3]=1;
        //arr[j][1],arr[j][2],arr[j][3],arr[cmp2(arr[j-1][1],arr[j-1][2],arr[j-1][3])]
        // dp[1]=arr[1][cmp1(arr[1][1],arr[1][2],arr[1][3])];
        for(int j=1;j<=n;j++){
            int aaa=1;
            if(b[cmp1(arr[j][1],arr[j][2],arr[j][3])]+1<=n/2)
                dp[j]=arr[j][cmp1(arr[j][1],arr[j][2],arr[j][3])]+dp[j-1];
            if(b[cmp2(arr[j][1],arr[j][2],arr[j][3])]+1<=n/2){
                if(arr[j][cmp2(arr[j][1],arr[j][2],arr[j][3])]+dp[j-1]>dp[j]) aaa=2;
                dp[j]=max(dp[j],arr[j][cmp2(arr[j][1],arr[j][2],arr[j][3])]+dp[j-1]);
            }  
            if(b[cmp3(arr[j][1],arr[j][2],arr[j][3])]+1<=n/2)
                if(arr[j][cmp3(arr[j][1],arr[j][2],arr[j][3])]+dp[j-1]>arr[j][cmp1(arr[j][1],arr[j][2],arr[j][3])]+dp[j-1] && arr[j][cmp3(arr[j][1],arr[j][2],arr[j][3])]+dp[j-1]>arr[j][cmp2(arr[j][1],arr[j][2],arr[j][3])]) aaa=3;
                dp[j]=max(dp[j],arr[j][cmp3(arr[j][1],arr[j][2],arr[j][3])]+dp[j-1]);
            b[aaa]++;
            printf("%d\n",dp[j]);
        }
        printf("%d\n",dp[n]);
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}