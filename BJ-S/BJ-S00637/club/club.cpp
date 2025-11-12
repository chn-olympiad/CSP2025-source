#include<iostream>
#include<cstdio>
#include<queue>
#include<bitset>
using namespace std;

#define IFD if(1)
const int maxval=1e3/2+5;
int dp[2][maxval][maxval][maxval];
#define T ((t)%2)
#define PREV ((t-1)%2)
int t,n;
struct man{
    int satisfy,id;
    bool operator< (const man &b) const{
        // satisfication big to small
        return satisfy<b.satisfy;
    }
};
bitset<114514> taken;
bool spA=1,spB=1;
int as1[114514],as2[114514],as3[114514];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        priority_queue<man> pqc1,pqc2,pqc3;
        int s1,s2,s3;
        int c1c=0,c2c=0,c3c=0;
        for(int i=1;i<=n;++i){
            scanf("%d%d%d",&s1,&s2,&s3);
            as1[i]=s1;
            as2[i]=s2;
            as3[i]=s3;
            if(s2!=0)spA=0;
            if(s3!=0)spA=spB=0;
            pqc1.push({s1,i});
            pqc2.push({s2,i});
            pqc3.push({s3,i});
        }
        int LIMIT=n/2;
        if(spA){ // only contrib club1
            int ans=0;
            for(int i=1;i<=LIMIT&&!pqc1.empty();++i){
                ans+=pqc1.top().satisfy;
                pqc1.pop();
            }
            printf("%d\n",ans);
            continue;
        }
        int ans=0;
        for(int i=0;i<=LIMIT;++i){
            for(int j=0;j<=LIMIT;++j){
                for(int k=0;k<=LIMIT;++k){
                    dp[0][i][j][k]=0;
                    dp[1][i][j][k]=0;
                }
            }
        }
        for(int t=1;t<=n;++t){
            for(int i=0;i<=min(LIMIT,t);++i){
                for(int j=0;j<=min(LIMIT,t);++j){
                    // i+j+k<=n
                    // k<=
                    for(int k=max(t-i-j,0);k<=min(LIMIT,t);++k){
                        //int k=n-i-j;
                        // if(!i&&!j&&!k)continue;
                        // if(i+j+k!=t)continue;
                        #define CUR dp[t%2][i][j][k]
                        CUR=dp[PREV][i][j][k];
                        if(i)CUR=max(CUR, dp[PREV][i-1][j][k]+as1[t]);
                        if(j)CUR=max(CUR,dp[PREV][i][j-1][k]+as2[t]);
                        if(k)CUR=max(CUR,dp[PREV][i][j][k-1]+as3[t]);

                        if(t==n){
                            ans=max(ans,dp[n%2][i][j][k]);
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}