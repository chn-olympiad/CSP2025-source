#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
int dp[maxn];
int n;
long long sum[maxn];
long long a[maxn];
long long k;
inline long long read(){
    long long res=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        res=res*10+ch-'0';
        ch=getchar();
    }
    return res*f;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n=read();
    k=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        sum[i]=sum[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            int x=0;
            if((sum[i]^sum[j])==k){
                x++;
            }
            dp[i]=max(dp[i],dp[j]+x);
        }
    }
    cout<<dp[n];
    return 0;
}
