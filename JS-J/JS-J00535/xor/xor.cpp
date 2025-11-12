#include<bits/stdc++.h>
using namespace std;
int n,a[500005],k,r[500005],l[500005],dp[500005],res;
bool flag=true;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]>1)  flag=false;
    }
    if(flag){
        int res=0;
        for(int i=1;i<=n;i++)   if(a[i]==k) res++;
        cout << res;
        return 0;
    }
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=i;j<=n;j++){
            sum^=a[j];
            if(sum==k){
                l[j]=i;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        dp[i]=max(dp[i-1],(l[i]?dp[l[i]-1]+1:0));
        res=max(res,dp[i]);
    }
    cout << res;
    return 0;
}
