#include <bits/stdc++.h>
using namespace std;
struct node {
    long long l,r;
}b[10005];
long long n,k,a[10005]={},q=0,w=0,z[10005][10005]={},l=0;
long ans=0,dp[10005]={};
long long xo(long long x,long long y) {
    long long x1[10005]={},y1[10005]={},sum=0;
    for (long long i=128,j=7;j>=0;i/=2,j--) {
        if (x>=i) x1[j]=1,x-=i;
        if (x==0) break;
    }
    for (long long i=128,j=7;j>=0;i/=2,j--) {
        if (y>=i) y1[j]=1,y-=i;
        if (y==0) break;
    }
    for (long long i=7,j=128;i>=0;i--,j/=2) {
        if (x1[i]!=y1[i])
            sum+=j;
    }
    return sum;
}
int main () {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (long long i=1;i<=n;i++) {
        cin >> a[i];
        if (a[i]!=0) q=1;
        if (a[i]!=1 && a[i]!=0) w=1;
    }
    if (q==0 && k==0) {
        cout << n/2;
        return 0;
    }
    if (w==0 && k==0) {
        for (long long i=1;i<=n;i++) {
            if (a[i]==0)
                ans++;
        }
        cout << ans;
        return 0;
    } else if (w==0 && k==1) {
        for (long long i=1;i<=n;i++) {
            if (a[i]==1)
                ans++;
        }
        cout << ans;
        return 0;
    }
    for (long long i=1;i<=n;i++) {
        for (long long j=1;j<=i;j++) {
            if (i==j) z[i][j]=a[i];
            else z[i][j]=xo(z[i-1][j],a[i]);
            if (z[i][j]==k) b[++l].l=j,b[l].r=i;
        }
    }
    for (long long i=1;i<=l;i++) {
        dp[i]=1,ans=max(long(1),ans);
        for (long long j=1;j<i;j++) {
            if (b[j].r<b[i].l && b[j].l<b[i].l) {
                dp[i]=max(dp[i],dp[j]+1),ans=max(ans,dp[i]);
            }
        }
    }
    cout << ans;
    return 0;
}
