#include<bits/stdc++.h>
#define maxn 505
#define mod 998244353
using namespace std;
int c[maxn],sum[maxn],k[maxn];
long long s[maxn];
long long cost(int n){
    long long ans=1;
    for(int i=1;i<=n;i++)
        ans=(ans*i)%mod;
    return ans%mod;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    sum[0]=0;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=0;i<s.length();i++){
        sum[i+1]=sum[i]+int(s[i]-'0');
    }
    long long x=cost(n)%mod;
    for(int i=1;i<=n;i++){
        int t=0;
        while(sum[t]<c[i])
            t++;
        k[i]=n-t+1;

    }
    for(int i=2;i<=n;i++){
        k[i]=(min(k[i],k[i-1])%mod)*((max(k[i],k[i-1])-1)%mod)%mod;
    }
    cout<<x-k[n];
    return 0;
}
