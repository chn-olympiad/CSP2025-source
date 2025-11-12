#include<bits/stdc++.h>
using namespace std;

long long dp[1048576][20];
bool s[20];
int c[20];

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        char ss;
        cin>>ss;
        s[i]=(ss-'0');
    }
    for(int i=0;i<n;i++)cin>>c[i];

    dp[0][0]=1;
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<=n;j++){
            // printf("dp[%d][%d]:%lld\n",i,j,dp[i][j]);
            dp[i][j]%=998244353;
            int allcnt=0;
            for(int k=0;k<n;k++)if((i>>k)&1)allcnt++;
            int no_lq=allcnt-j;
            for(int k=0;k<n;k++)
                if(((i>>k)&1)==0){
                    if(s[allcnt]&&no_lq<c[k])dp[i+(1<<k)][j+1]+=dp[i][j];//,cout<<(i+(1<<k))<<' '<<m+1<<endl;
                    else dp[i+(1<<k)][j]+=dp[i][j];//,cout<<(i+(1<<k))<<' '<<m<<endl;
                }
        }
    
    

    long long ans=0;
    for(int i=m;i<=n;i++)ans+=dp[(1<<n)-1][i];
    cout<<ans;

}

/*
我不要上文化课！
我不要上文化课！
我不要上文化课！
我不要上文化课！
我不要上文化课！
我不要上文化课！
我不要上文化课！
我不要上文化课！
我不要上文化课！
我不要上文化课！
我不要上文化课！
我不要上文化课！
我不要上文化课！
我不要上文化课！
我不要上文化课！
*/