#include<bits/stdc++.h>
using namespace std;
int t,n;
struct Q{
    int add,x,y,z;
}a[1000005];
bool cmp(Q a,Q b){
    return a.add>b.add;
}
int book[5];
int dp[1000005][5];
int sum[100005];
int main(){
    ios::sync_with_stdio(0);
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        memset(book,0x3f,sizeof(book));
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        cin>>n;
        for(int i=1;i<=n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            a[i].add=x+y+z;
            a[i].x=x;
            a[i].y=y;
            a[i].z=z;
        }
        sort(a+1,a+n+1,cmp);
        int jsq=0;
        dp[0][1]=dp[0][2]=dp[0][3];
        for(int i=1;i<=n;i++){
            int maxn=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]));
            for(int j=1;j<=3;j++){
                if(sum[j]<n/2){
                    if(j==1) dp[i][1]=max(dp[i][1],a[i].x+maxn),sum[j]++;
                    if(j==2) dp[i][2]=max(dp[i][2],a[i].y+maxn),sum[j]++;
                    if(j==3) dp[i][3]=max(dp[i][3],a[i].z+maxn),sum[j]++;
                }
                else{
                    if(j==1) dp[i][1]=max(dp[i][1],a[i].x+max(a[i-1].y,a[i-1].z));
                    if(j==2) dp[i][2]=max(dp[i][2],a[i].y+max(a[i-1].x,a[i-1].z));
                    if(j==3) dp[i][3]=max(dp[i][3],a[i].z+max(a[i-1].y,a[i-1].x));
                }

            }
            //cout<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<endl;
        }
        cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
    }
    return 0;
}
