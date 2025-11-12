#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int cnt[5050],n,a[5050],c[5050][5050],ans,cnt1[5050];
void init(){
    c[0][0]=1;
    for(int i=1;i<=5000;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++){
            c[i][j]=c[i-1][j-1]+c[i-1][j];
            c[i][j]%=MOD;
        }
    }
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    init();
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    cnt[a[1]]++,cnt[a[2]]++;
    if(a[1]+a[2]<=5000) cnt[a[1]+a[2]]++;
    for(int i=3;i<=n;i++){
        int res=0;
        for(int j=1;j<i;j++){
            res+=c[i-1][j];
        }
        for(int j=1;j<=+a[i];j++){
            res-=cnt[j];
        }
        ans+=res;
        ans%=MOD;
        if(ans<0) ans+=MOD;
        for(int j=1;j<=5000;j++){
            cnt1[j]=cnt[j];
        }
        for(int j=1;j<=5000-a[i];j++){
            cnt[j+a[i]]+=cnt1[j];
        }
        cnt[a[i]]++;
    }
    cout<<ans;
    return 0;
}
