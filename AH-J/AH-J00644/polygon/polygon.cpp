#include <bits/stdc++.h>
#define int long long
#define gc getchar_unlocked
int read(){
    int x=0,f=0;char c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c))x=x*10+c-'0',c=gc();
    return f?-x:x;
}
using namespace std;
const int dd=5e4+5;
int a[dd];int n;
int dp[dd];
const int M=998244353;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    n=read();int mxn=0;
    for(int i=1;i<=n;i++){a[i]=read();mxn=max(mxn,a[i]);}
    sort(a+1,a+1+n);int ans=0;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=a[i]+1;j<=mxn+1;j++)ans=(ans+dp[j])%M;
        for(int j=mxn+1;j>=mxn+1-a[i];j--)dp[mxn+1]=(dp[mxn+1]+dp[j])%M;
        for(int j=mxn;j>=a[i];j--){
            dp[j]+=dp[j-a[i]];
            dp[j]%=M;
        }
    }
    cout<<ans%M;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
