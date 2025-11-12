#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
string s;
int a[505],tong[505],cnt[505],n,k;
long long ans=1;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>k;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        if(s[i]=='0') cnt[i]++;
        cnt[i]+=cnt[i-1];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;a[i]>cnt[j];j++) tong[j]++;
    }
    for(int i=1;i<=k;i++){
        if(tong[i]<=1) {
            for(int j=1;j<i;j++){
                if(tong[j]>1) tong[j]--;
            }
        }
    }
    int biao=tong[1];
    for(int i=2;i<=n;i++)
        if(tong[i]>biao-i+1&&biao-i+1>0) tong[i]=biao-i+1;
    for(int i=1;i<=n;i++){
        if(tong[i]!=0) ans=(ans*tong[i])%Mod;
    }
    cout<<ans;
    return 0;
}
