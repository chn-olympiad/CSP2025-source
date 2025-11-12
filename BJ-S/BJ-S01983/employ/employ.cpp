#include<bits/stdc++.h>
using namespace std;
int n,m;
int jiji[1000];
long long ans=0;
const int M=998244353;
long long dp[1000][1000];
string s;
int a[1000];
long long q(int x){
    if(x==1||x==0) return 1;
    else return x*q(x-1)%M;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        jiji[a[i]]++;
    }
    sort(a+1,a+n+1,greater<int>());
    for(int y=m;y<=n;y++){
        for(int i=1;i<=n;i++){
            if(s[i]=='1'&&a[y]>i-1) dp[i][1]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=2;j<=y;j++){
                dp[i][j]=0;
                if(i-j>=a[y-j+1]) continue;
                if(s[i]=='0') continue;
                for(int k=1;k<i;k++){
                    dp[i][j]=(dp[i][j]+dp[k][j-1])%M;
                }
            }
        }
        for(int i=y;i<=n;i++) ans=(ans+(q(n-y)*dp[i][y]))%M;
    }
    for(int i=1;i<=n;i++){
        ans=ans*q(jiji[i])%M;
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}