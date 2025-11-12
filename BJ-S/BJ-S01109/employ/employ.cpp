#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int c[510];
int dp[510],a[510],b[510];
long long ans[510];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++) {
        cin>>c[i];
    }
    b[0]=n;
    for(int i=n;i>=1;i--) {
        b[i]=b[i+1];
        for(int j=1;j<=n;j++) {
            if(c[i]==i) {
                b[i]++;
            }
        }
    }
    s='0'+s;
    for(int i=1;i<=n;i++) {
        if(i=='0') {
            a[i]=a[i-1]+1;
        }
        else {
            a[i]=a[i-1];
        }
    }

    long long sum=0;
    if(a[n]==0) {
        for(int i=1;i<=n;i++) {
            ans[i]*=(n-i+1);
            ans[i]%=mod;
            if(i>=m) {
                sum+=ans[i];
            }
        }
        cout<<sum;
        return 0;
    }
    ans[n+1]=1;
    for(int i=n;i>=1;i--) {
        dp[i]=dp[i+1];
        ans[i]=ans[i+1];
        if(s[i]=='1'&&b[a[i]]>=1) {
            ans[i]*=b[a[i]];
            dp[i]++;
            ans[i]%=mod;
            if(dp[i]>=m) {
				sum+=ans[i];
			}
        }
        
    }
    cout<<sum;
    return 0;
}
