#include<bits/stdc++.h>
using namespace std;
#define p 998244353
#define ppc __builtin_popcount
int n,m;
string s;
bool sb[23];
int dp[23][1<<19],c[23];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++){
        sb[i]=s[i-1]-'0';
        scanf("%d",c+i);
    }
    dp[0][0]=1;
    for(int s=0;s<(1<<n);s++){
        for(int j=0;j<=ppc(s);j++){
            for(int k=0;k<n;k++)
                if(!((s>>k)&1)){
                    int t=s|(1<<k);
                    if(sb[ppc(s)+1]&&ppc(s)-j<c[k+1])
                        (dp[j+1][t]+=dp[j][s])%=p;
                    else
                        (dp[j][t]+=dp[j][s])%=p;
                }   
        }
    }
    int ans=0;
    for(int i=m;i<=n;i++)
        (ans+=dp[i][(1<<n)-1])%=p;
    printf("%d\n",ans);
    return 0;
}