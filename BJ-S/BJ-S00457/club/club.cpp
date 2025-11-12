#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
long long n,T,max_ans=0,num1=0,num2=0;
long long f[maxn],f1[maxn],f2[maxn];
struct st{
    long long x,y,z;
}a[maxn];
int main(int argc,char** argv){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].y==0&&a[i].z==0){
                num1++;
                f[i]=a[i].x;
            }
            if(a[i].z==0){
                num2++;
            }
        }
        if(num1==n){
            sort(f+1,f+1+n);
            long long sum=0;
            for(int i=n;i>n/2;i--){
                sum+=f[i];
            }
            cout<<sum<<endl;
            continue;
        }
        long long dp[205][205][205];
        memset(dp,0,sizeof(dp));
        max_ans=0,num1=0;
        for(int i=0;i<=n/2;i++){
            for(int j=0;j<=n/2;j++){
                for(int k=0;k<=n/2;k++){
                    if(i+j+k>n) continue;
                    if(i>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i+j+k].x);
                    if(j>0) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[i+j+k].y);
                    if(k>0) dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[i+j+k].z);
                    //cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
                    if((i+j+k)==n) max_ans=max(max_ans,dp[i][j][k]);
                }
            }
        }
        cout<<max_ans<<endl;
        //cout<<endl;
    }
    return 0;
}
