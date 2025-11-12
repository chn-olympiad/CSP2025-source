#include<bits/stdc++.h>
using namespace std;
const int MAXN=500006;
int n;
long long k;
long long a[MAXN];
int dp[MAXN];
int last[MAXN];
int st[MAXN];
void deal(int x){
    if(dp[x]<dp[x-1])dp[x]=dp[x-1];
    int c=a[x];
    int p=x;
    while(c!=k&&p!=n){
        p+=1;
        c^=a[p];
    }
    if(c==k){
        for(int i=x;i<=p;i++){
            int k=last[i];
            while(last[k]>=x){
                k=st[k]-1;
            }
            if(dp[i]<dp[last[k]]+1){
                dp[i]=dp[last[k]]+1;
                last[i]=p;
                st[i]=x;
            }
        }
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)last[i]=i-1;
    for(int i=1;i<=n;i++)deal(i);
    cout<<dp[n]<<endl;
    return 0;
}
