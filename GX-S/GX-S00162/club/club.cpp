#include<bits/stdc++.h>
using namespace std;
struct node{
    int shu,a,b,c;
    node(){}
    node(int x0,int x1,int x2,int x3){
        shu=x0;
        a=x1;
        b=x2;
        c=x3;
    }
}dp[100010][10];
node mb(node x,node y){
    if(x.shu>y.shu) return x;
    return y;
}
int n,t,s[100010][10],maxx=0;
void f(int a,int b,int c,int cc,int ans){
    if(cc==n+1){
        maxx=max(maxx,ans);
        return;
    }
    if(a<n/2) f(a+1,b,c,cc+1,ans+s[cc][1]);
    if(b<n/2) f(a,b+1,c,cc+1,ans+s[cc][2]);
    if(c<n/2) f(a,b,c+1,cc+1,ans+s[cc][3]);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        maxx=0;
        memset(dp,0,sizeof(dp));
        memset(s,0,sizeof(s));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i][1]>>s[i][2]>>s[i][3];
        }
        if(n<=50){
            f(0,0,0,1,0);
            cout<<maxx<<endl;
        }
        else{
            for(int i=1;i<=n;i++){
                for(int j=1;j<=3;j++){
                    node sum=node(0,0,0,0);
                    for(int k=1;k<=3;k++){
                        int bj;
                        node ans;
                        if(j==1){
                            bj=dp[i-1][k].a;
                            if(bj==n/2) continue;
                            ans=node(dp[i-1][k].shu+s[i][j],dp[i-1][k].a+1,dp[i-1][k].b,dp[i-1][k].c);
                            sum=mb(ans,sum);
                        }
                        else if(j==2){
                            bj=dp[i-1][k].b;
                            if(bj==n/2) continue;
                            ans=node(dp[i-1][k].shu+s[i][j],dp[i-1][k].a,dp[i-1][k].b+1,dp[i-1][k].c);
                            sum=mb(ans,sum);
                        }
                        else if(j==3){
                            bj=dp[i-1][k].c;
                            if(bj==n/2) continue;
                            ans=node(dp[i-1][k].shu+s[i][j],dp[i-1][k].a,dp[i-1][k].b,dp[i-1][k].c+1);
                            sum=mb(ans,sum);
                        }

                    }
                    dp[i][j]=sum;
                }
            }
            node zx;
            for(int i=1;i<=3;i++){
     //           cout<<dp[n][i].shu<<" "<<dp[n][i].a<<" "<<dp[n][i].b<<" "<<dp[n][i].c<<endl;
                zx=mb(zx,dp[n][i]);
            }
            cout<<zx.shu<<endl;
        }

    }
    return 0;
}
