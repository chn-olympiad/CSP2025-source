#include<bits/stdc++.h>
using namespace std;
long long dp[50005],a[50005];
long long k,n;
bool f(long long l,long long r){
    long long cnt=0;
        cnt=a[l];
        for(long long i=l;i<r;i++)
            cnt=cnt^a[i+1];
            if(cnt==k)return 1;
    return 0;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        long long cnt=dp[i-1];
        for(int mid=1;mid<i;mid++){
            if(f(mid+1,i))
            cnt=max(dp[mid]+1,cnt);
        }
        dp[i]=cnt;
    }
   cout<<dp[n];
    return 0;
}
