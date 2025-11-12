#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,cnt=0;
int a[500005],q[500005],dp[500005];
int l[5000005],r[5000005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    q[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q[i]=q[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            if((q[i]^q[j-1])==k){
                l[++cnt]=j;
                r[cnt]=i;
            }
        }
    }
    r[0]=0;
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=cnt;i++){
        int x;
        int left=0,right=i-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(r[mid]>=l[i]){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        if(left==0)x=0;
        else x=left-1;
        dp[i]=max(dp[i-1],dp[x]+1);
    }
    cout<<dp[cnt];
    return 0;
}
