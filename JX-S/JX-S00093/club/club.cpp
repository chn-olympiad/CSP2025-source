#include<cstdio>
using namespace std;
int w[100001][4],n,t;
int max(int a,int b){
    return a>b?a:b;
}
int max(int a,int b,int c){
    return max(a,max(b,c));
}
int dfs(int cur,int n1,int n2,int n3);
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d",&n);
        for(int j=1;j<=n;j++){
            int a1,a2,a3;
            scanf("%d %d %d",&a1,&a2,&a3);
            w[j][1] = a1;
            w[j][2] = a2;
            w[j][3] = a3;
        }
        printf("%d\n",dfs(0,0,0,0));
    }
    return 0;
}
inline int dfs(int cur,int n1,int n2,int n3){
    if(cur==4)
        return 0;
    int v1,v2,v3;
    if(n1==n/2)
        v1=0;
    else
        v1=dfs(cur+1,n1+1,n2,n3)+w[cur+1][1];
    if(n2==n/2)
        v2=0;
    else
        v2=dfs(cur+1,n1,n2+1,n3)+w[cur+1][2];
    if(n3==n/2)
        v3=0;
    else
        v3=dfs(cur+1,n1,n2,n3+1)+w[cur+1][3];
    return max(v1,v2,v3);
}
