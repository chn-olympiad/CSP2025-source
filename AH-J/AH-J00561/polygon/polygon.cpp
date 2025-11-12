#include<bits/stdc++.h>
using namespace std;
const long long inf=998244353;
int n;
long long a[5005],dp[5005][5005],dp1[5005][5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    bool flag=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //sum[i]+=(long long)
        if(a[i]!=1) flag=1;
    }
    if(!flag){
        long long ans=0;
        for(int i=3;i<=n;i++){
            long long sum1=1,sum2=1;
            for(int j=n;j>=n-i+1;j--){
                sum2=(sum2*(long long)j)%inf;
                sum1=(sum1*(long long)(n-j+1))%inf;
            }
            sum2=(sum2/sum1)%inf;
            ans=(ans+sum2)%inf;
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+1+n);
    long long final_ans=0;
    for(int i=3;i<=n;i++){
        for(int j=3;j<=i;j++){
            for(int k=1;k<(1<<i);k++){
                long long ans=0,num=0;
                for(int p=0;p<i;p++){
                    if(k&(1<<p)){
                        num++;
                        ans=(ans+a[p+1])%inf;
                    }
                }
                if(num!=j) continue;
                if((k&(1<<(i-1)))==0) continue;
                if(ans>2*a[i]) dp[i][j]=(dp[i][j]+1)%inf;
            }
            final_ans=(final_ans+dp[i][j])%inf;
        }
    }
    cout<<final_ans;
    return 0;
}
