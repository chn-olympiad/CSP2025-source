#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,P=998244353;
int n,a[N],s[N],dp[N];

int ksm(int a,int b){
    int res=1,base=a;
    while(b){
        if(b&1)res=res*base%P;
        base=base*base%P;
        b>>=1;
    }
    return res;
}

int C(int n,int m){
    int sum1=1;
    for(int i=n-m+1;i<=n;i++)sum1=sum1*i%P;
    int sum2=1;
    for(int i=1;i<=m;i++)sum2=sum2*i%P;
    return sum1*ksm(sum2,P-2)%P;
}

int fft(int x){
    memset(dp,0,sizeof dp);
    dp[0]=1;
    for(int i=1;i<x;i++){
        for(int j=a[x];j>=a[i];j--){
            dp[j]+=dp[j-a[i]];
            dp[j]%=P;
        }
    }
    int sum=0;
    for(int i=1;i<=a[x];i++){
        sum+=dp[i];
        sum%=P;
    }
    sum=sum-x+1+P;
    return sum%P;
}

signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    sort(a+1,a+n+1);
    int ans=0;
    for(int l=2;l<n;l++){
        ans+=C(n,l+1)+P;
        ans%=P;
    }
    int sum=0;
    for(int i=n;i>=1;i--){
        sum+=fft(i);
        sum%=P;
    }
    cout<<(ans-sum+P)%P;
    return 0;
}
