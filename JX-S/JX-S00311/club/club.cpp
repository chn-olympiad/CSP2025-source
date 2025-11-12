#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+5;
int n,ans,det[maxn];
struct node{
    int a,b,c;
    void in(){
        scanf("%d%d%d",&a,&b,&c);
    }
}x[maxn];
bool cmp(node e1,node e2){
    if(e1.a!=e2.a)return e1.a>e2.a;
    else return e1.b>e2.b;
}
bool cmp1(int a,int b){
    return a>b;
}
int dp[35][35][35];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)x[i].in();
        if(n<=2)printf("%d",max(x[1].a+max(x[2].b,x[2].c),max(x[1].b+max(x[2].a,x[2].c),x[1].c+max(x[2].b,x[2].a))));
        /*
        if(n<=30){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n/2;j++){
                    for(int k=1;k<=n/2;k++){
                        int y=i-j-k;
                        if(y>n/2)continue;
                        dp[i][j][k]=0;
                    }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n/2;j++){
                    for(int k=1;k<=n/2;k++){
                        int y=i-j-k;
                        if(y>n/2)continue;
                        if(j<=n/2){
                            dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+x[i].a);
                        }
                        if(k<=n/2){
                            dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+x[i].b);
                        }
                        if(y<=n/2){
                            dp[i][j][k]=max(dp[i][j][k],max(dp[i-1][j][k-1]+x[i].c,dp[i-1][j-1][k]+x[i].c));
                        }
                    }
                }
            }
            for(int i=1;i<=n/2;i++){
                for(int j=1;j<=n/2;j++)ans=max(ans,dp[n][i][j]);
            }
        }
        else {
                */
            sort(x+1,x+n+1,cmp);
            //printf("%d",x[1].a);
            for(int i=1;i<=n;i++)det[i]=x[i].a-x[i].b;
            for(int i=1;i<=n/2;i++)ans+=x[i].a;
            for(int i=n/2+1;i<=n;i++)ans+=x[i].b;
            sort(det+1,det+n/2+1);
            sort(det+n/2+1,det+n+1,cmp1);
            int now=1;
            while(det[now+n/2]-det[now]>0){
                ans+=det[now+n/2]-det[now];
                now++;
            }
        //}
        printf("%d\n",ans);
    }
    return 0;
}
