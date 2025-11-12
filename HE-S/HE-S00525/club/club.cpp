#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct str{
    int num;
    int d1,d2,d3;
}a[100005];

bool f(str a, str b){
    return a.d1>b.d1;
}
int dp[100005][4];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t;
    scanf("%d",&t);
    for(int i=0; i<t; ++i){
        int n;
        scanf("%d",&n);

        int cnt1=0,cnt2=0,cnt3=0;
        int j=1;
        for( ; j<=n; ++j){
            scanf("%d%d%d",&a[j].d1,&a[j].d2,&a[j].d3);
            dp[j][1]=max(dp[j-1][2],dp[j-1][3])+a[j].d1;
            dp[j][2]=max(dp[j-1][1],dp[j-1][3])+a[j].d2;
            dp[j][3]=max(dp[j-1][2],dp[j-1][1])+a[j].d3;
        }
        if(!a[j].d2 && !a[j].d3){
            sort(a+1,&a[n+1],f);
            int ans=0;
            for(int j=1; j<=n/2; ++j)
                ans+=a[j].d1;
            printf("%d",ans);
        }
        else{
            printf("%d",max(dp[n][3],max(dp[n][1],dp[n][2])));
        }
    }

    return 0;

}
