#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005][3],f[100005],g[100005],dp[100005][3],t,n,ans=0;
bool cmp(int a,int b){
    return a>b;
}
int max3(int x,int y,int z){
    return max(x,max(y,z));
}
void dfs1(int c1,int c2,int c3,int step,int tot){
    if(step==n){
        ans=max(ans,tot);
        return;
    }
    if(c1<n/2) dfs1(c1+1,c2,c3,step+1,tot+a[step][0]);
    if(c2<n/2) dfs1(c1,c2+1,c3,step+1,tot+a[step][1]);
    if(c3<n/2) dfs1(c1,c2,c3+1,step+1,tot+a[step][2]);
    return;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>> t;
    while(t--){
        ans=0;
        memset(dp,0,sizeof dp);
        cin>> n;
        int c1=0,c2=0;
        for(int i=1;i<=n;i++){
            cin>> a[i][0] >> a[i][1] >> a[i][2];
            if(a[i][1]!=0) c1++;
            if(a[i][2]!=0) c2++;
        }
        if(c1==0 && c2==0){
            for(int i=1;i<=n;i++) f[i]=a[i][0];
            sort(f+1,f+n+1,cmp);
            for(int i=1;i<=n/2;i++) ans+=f[i];
            cout<< ans;
            return 0;
        }else if(c2==0){
            for(int i=1;i<=n;i++) ans+=max(a[i][0],a[i][1]);
            cout<< ans;
            return 0;
        }else if(n<=10){
            dfs1(0,0,0,0,0);
            cout<< ans;
            return 0;
        }else{
            int p0=0,p1=0,p2=0;
            for(int i=1;i<=n;i++){
                for(int j=0;j<3;j++){
                    dp[i][j]=max3(dp[i-1][0],dp[i-1][1],dp[i-1][2])+a[i][j];
                }
            }
        }
    }
    cout<< max3(dp[n][0],dp[n][1],dp[n][2]);
    return 0;
}
