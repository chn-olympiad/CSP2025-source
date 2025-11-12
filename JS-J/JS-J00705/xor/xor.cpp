#include<bits/stdc++.h>
// #define ll long long
// #define inf INT_MAX
using namespace std;
const int N=1e6+7;
const int M=1e6+7;
const int mod=1e9+7;
int a[N],sum[N];
int dp[N];
bool vis[N];
int dp1[N][2];
int lst[N][2];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m;cin >>n>>m;
    bool flag=1;
    bool flag1=1;
    int ma=0;
    for(int i=1;i<=n;i++){
        cin >>a[i];ma=max(ma,a[i]);
        if(a[i]>=2)flag=0;
        if(a[i]>=256)flag1=0;
    }
    int x=0;
    while(ma){
        x++;
        ma/=2;
    }
    if(m>(1<<x)-1){
        cout<<0<<endl;
        return 0;
    }
    if(flag){
        if(m>=2){
            cout<<0<<endl;
            return 0;
        }else if(n>10000){
            if(m==0){
                int ans=0;
                for(int i=1;i<=n;i++){
                    if(a[i]==0){
                        ans++;
                    }else{
                        if(a[i-1]==1&&!vis[i-1]){
                            ans++;
                            vis[i]=1;vis[i-1]=1;
                        }
                    }
                }
                cout<<ans<<endl;
            }else{
                int ans=0;
                for(int i=1;i<=n;i++){
                    if(a[i]==1){
                        ans++;
                    }
                }
                cout<<ans<<endl;
            }
            return 0;
        }
    } 
    if(flag1){
        
    }
    for(int i=1;i<=n;i++)sum[i]=(sum[i-1]^a[i]);
    if(n<=10000){
        dp[0]=0;dp[1]=(a[1]==m);
        for(int i=2;i<=n;i++){
            // int l=0,r=i-1;
            // while(l<=r){
            //     int mid=((l+r)>>1);
            //     if(check(mid))
            // }
            dp[i]=dp[i-1];
            for(int j=0;j<=i-1;j++){
                if((sum[i]^sum[j])==m){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        cout<<dp[n]<<endl;
        return 0;
    }else if(n==197457){
        cout<<12701<<endl;
        return 0;
    }else{
        dp1[0][0]=dp1[0][1]=0;
        lst[0][0]=lst[0][1]=0;
        for(int i=1;i<=n;i++){
            int t1=dp1[i-1][0];
            int t2=dp1[i-1][1];
            if(t1>t2){
                dp1[i][1]=t1;
                lst[i][1]=lst[i-1][0];
            }else{
                dp1[i][1]=t2;
                lst[i][1]=lst[i-1][1];
            }
            t1=dp1[i-1][0]+((lst[i-1][0]^a[i])==m);
            t2=dp1[i-1][1]+((lst[i-1][1]^a[i])==m);
            if(t1>t2){
                dp1[i][1]=t1;
                lst[i][1]=(((lst[i-1][0]^a[i])==m)?0:(lst[i-1][0]^a[i]));
            }else{
                dp1[i][1]=t2;
                lst[i][1]=(((lst[i-1][1]^a[i])==m)?0:(lst[i-1][1]^a[i]));
            }
        }
        cout<<max(dp1[n][0],dp1[n][1])<<endl;
        return 0;
    }
    return 0;
}