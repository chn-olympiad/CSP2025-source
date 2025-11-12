#include<iostream>
#include<cstring>
using namespace std;

const int N=1e5+2;

int a[N][3];

int T,n;

int dfs(int r1,int r2,int r3,int t){
    if(t>=n) return 0;

    int w1=0,w2=0,w3=0;
    if(r1>0)w1=dfs(r1-1,r2,r3,t+1)+a[t][0];
    if(r2>0)w2=dfs(r1,r2-1,r3,t+1)+a[t][1];
    if(r3>0)w3=dfs(r1,r2,r3-1,t+1)+a[t][2];

    return max(w1,max(w2,w3));
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++) scanf("%d",&a[i][j]);
        }
        int res=dfs(n/2,n/2,n/2,0);
        printf("%d\n",res);
        T--;
    }
    fclose(stdin);
    fclose(stdout);
}
