#include<bits/stdc++.h>
#define inf 1000000000
using namespace std;
const int N=500005,M=(1<<20);
template<class T>
void chkmx(T& x,const T& y){
    x=(x>y?x:y);
}
int dp[N],mx[M],a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) a[i]^=a[i-1];
    for(int i=0;i<M;i++) mx[i]=-inf;
    for(int i=1;i<=n;i++) dp[i]=-inf;
    dp[0]=0;
    mx[0]=0;
    for(int i=1;i<=n;i++){
        chkmx(dp[i],dp[i-1]);
        chkmx(dp[i],mx[a[i]^k]+1);
        chkmx(mx[a[i]],dp[i]);
    }
    cout<<dp[n];
}