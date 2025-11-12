#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 998244353;
ll n,m,ans,num;
string s;
ll dif[509],a[509],sum[509];
ll cheng(ll a){
    if(a==1)return 1;
    return a*cheng(a-1)%mod;
}
bool cmp(ll a,ll b){
    return a > b;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    cin>>s;
    int t=0;
    for(int i=1;i<=n;++i){
        dif[i]=s[i-1]-'0';
        if(dif[i]==0)t=1;
        sum[i]=sum[i-1]+(1-dif[i]);
    }
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        if(a[i]==0)num++;
    }
    sort(a+1,a+n+1,cmp);
    if(n-num<m){
        printf("0");
    }
    else if(m==n){
        printf("0");
    }
    else if(t==0){
        for(int i=num+1;i<=n;++i){
            ans+=a[i]*cheng(n-1);

        }
        ans/=(n-num);
        ans%=mod;
        printf("%lld",ans);
    }
    else if(m==1){
        int q=1;
        while(dif[q]==0)q++;
        q--;
        for(int i=1;i<=n;++i){
            if(a[i]>=q)ans+=cheng(n-1);
            ans%=mod;
        }
        printf("%lld",ans);
    }
    else printf("0");
    return 0;
}
