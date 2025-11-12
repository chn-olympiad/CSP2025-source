#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n,k,a[N],dp[N],sum[N],mx = -1;
//bool check(int wx){
//
//}
//int qwq(int wx,int wx_id){
//    for(int flag = k;flag <= sum[n];flag += k){
//        int l = wx_id,r = n,mid,ans = 0;
//        while(l <= r){
//            mid = (l + r) >> 1;
//            if(sum[mid] - sum[wx_id - 1] == flag){
//                ans = mid;
//                r = mid - 1;
//            }else if(sum[mid] - sum[wx_id - 1] < flag){
//                l = mid + 1;
//            }else{
//                r = mid - 1;
//            }
//        }
//        if(ans){
//            return ans;
//        }
//    }
//    return 0;
//}
int32_t main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld %lld",&n,&k);
    for(int i = 1;i <= n;++i){
        scanf("%lld",&a[i]);
        sum[i] = sum[i - 1] ^ a[i];
    }
    for(int i = 1;i <= n;++i){
        for(int j = i;j <= n;++j){
            dp[j] = max(dp[j],dp[j - 1]);
            if((sum[j] ^ sum[i - 1]) == k) dp[j] = max(dp[j],dp[i - 1] + 1);
        }
    }
    for(int i = 1;i <= n;++i) mx = max(mx,dp[i]);
    printf("%lld",mx);
    return 0;
}
