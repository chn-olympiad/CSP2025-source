#include<bits/stdc++.h>
using namespace std;
int n,m,t,a[100005],b[100005],c[100005],mx[100005];
priority_queue<int> pq;
long long dfs(int i,int ca,int cb,int cc,long long cnt){
    if(ca>n/2||cb>n/2||cc>n/2)return 0;
    if(i>n)return cnt;
    return max(max(dfs(i+1,ca+1,cb,cc,cnt+a[i]),dfs(i+1,ca,cb+1,cc,cnt+b[i])),dfs(i+1,ca,cb,cc+1,cnt+c[i]));
}
long long  dp[205][205][205];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ab0=1,ac0=1;
        for(int i =1;i<=n;i++){
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            mx[i]=max(max(a[i],b[i]),c[i]);
            pq.push(mx[i]);
            if(b[i])ab0=0;
            if(c[i])ac0=0;
        }
        if(n<=20){
            cout<<dfs(1,0,0,0,0)<<endl;
        }
        else if(ab0&&ac0){
            long long ans =0;
            for(int i = 1;i<=n/2;i++){
                ans+=pq.top();
                pq.pop();
            }
            cout<<ans<<endl;
        }
        else if(n<=1000){
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<=min(i,n/2);j++){
                    for(int k = 1;k<=min(i-j,n/2);k++){
                        dp[i][j][k]=max(dp[i][j-1][k]+b[i],dp[i][j][k-1]+c[i])
                    }
                }
            }
            long long ans =0;
            for(int j = 1;j<=n/2;j++){
                for(int k = 1;k<=n/2;k++){
                    if(n-j-k>(n/2))continue;
                    ans = max(ans,dp[n][j][k]);
                }
            }
            cout<<ans<<endl;
        }

        else{
            long long ans =0;
            for(int i = 1;i<=n;i++){
                ans+=pq.top();
                pq.pop();
            }
            cout<<ans<<endl;            
        }
    }
    return 0;
}
