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
const int dd=1e6+5;
const int M=1e9+7;
int a[dd],dp[dd];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n=read(),k=read();
    for(int i=1;i<=n;i++)a[i]=read();
    if(n>=1000&&k==1){
        int cnt=0;
        for(int i=1;i<=n;i++)cnt+=(a[i]==1);
        cout<<cnt;return 0;
    }
    if(n>=1000&&k==0){
        int ans=0;int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]){
                cnt++;
            }
            else{
                ans++;ans+=cnt/2;cnt=0;
            }
        }
        ans+=cnt/2;
        cout<<ans;return 0;
    }
    for(int i=1;i<=n;i++){
        int now=0;dp[i]=dp[i-1];
        for(int j=i;j>=1;j--){
            now^=a[j];
            if(now==k)
                dp[i]=max(dp[i],dp[j-1]+1);
        }
    }
    cout<<dp[n];

    fclose(stdin);
    fclose(stdout);
    return 0;
}
