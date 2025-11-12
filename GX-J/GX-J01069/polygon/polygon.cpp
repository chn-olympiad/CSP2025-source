#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5005],maxx=INT_MIN;
long long cnt=0,cnt1=0,sum=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>maxx)cnt++;
        cout<<cnt;
        return 0;
    }
    for(int i=1;i<=n-2;i++){
        for(int j=i;j<=n;j++){
            cnt1++;
            sum+=a[j];
            if(cnt1<3) continue;
            for(int k=i;k<=j;k++) maxx=max(maxx,a[k]);
            if(sum>maxx*2) cnt++;
            maxx=INT_MIN;
        }
        sum=0;
        cnt1=0;
    }
    cout<<cnt%MOD;
    return 0;
}
