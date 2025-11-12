#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int x,y,z;
}student[100010];
long long t,n,ans,dp[40][20][20][20],flagA,flagB;
bool cmp(node a,node b){
    return a.x>b.x;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        memset(dp,0,sizeof(dp));
        int nn=n/2,flagA=0,flagB=0;
        for(int i=1;i<=n;i++){
            cin>>student[i].x>>student[i].y>>student[i].z;
            if(student[i].y||student[i].z) flagA=1;
            if(student[i].z) flagB=1;
        }
        if(flagA==0){
            int sum=0;
            sort(student+1,student+n+1,cmp);
            for(int i=1;i<=nn;i++){
                sum+=student[i].x;
            }
            cout<<sum<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int a=0;a<=min(i,nn);a++){
                for(int b=0;b<=min(i,nn);b++){
                    for(int c=0;c<=min(min(n-a-b,i),nn);c++){
                        if(a>=1) dp[i][a][b][c]=max(dp[i-1][a-1][b][c]+student[i].x,dp[i][a][b][c]);
                        if(b>=1) dp[i][a][b][c]=max(dp[i-1][a][b-1][c]+student[i].y,dp[i][a][b][c]);
                        if(c>=1) dp[i][a][b][c]=max(dp[i-1][a][b][c-1]+student[i].z,dp[i][a][b][c]);

                    }
                }
            }
        }
        ans=0;
        for(int a=0;a<=nn;a++){
            for(int b=0;b<=nn;b++){
                int c=min(n-a-b,nn);
                ans=max(ans,dp[n][a][b][c]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}