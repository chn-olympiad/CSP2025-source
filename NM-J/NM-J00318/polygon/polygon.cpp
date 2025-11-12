#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const ll N=22,P=998244353 ;
ll n,a[5010],sum=0,maxs=-1,ans=0;
int cou[1<<N],hi[1<<N];
void init(){
    for(int i=0;i<(1<<(N-1));i++){
        int cnt=0,ma=0;
        for(int j=0;j<=22;j++){
            if(i&(1<<j)){
                cnt++;
                ma=j;
            }
        }
        cou[i]=cnt;
        hi[i]=ma;
    }
}
long double fact[5010];
void i2(){
    fact[0]=1;
    for(int i=1;i<=5002;i++){
        fact[i]=fact[i-1]*i;
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    init();
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxs=max(maxs,a[i]);
    }
    sort(a+1,a+1+n);
    if(maxs==1&&n>N+2){
        i2();
        long double ans=0;
        for(int i=3;i<=n;i++){
            ans+=fact[n]/(fact[i]*fact[n-i]);
            long double tmp=ans-(ll)ans;
            ll mod=(ll)ans%P;
            ans=mod+tmp;
        }
        cout<<(ll)round(ans)%P;
        return 0;
    }
    for(int i=1;i<(1<<n);i++){
        if(cou[i]>=3){
            sum=0;
            for(int j=0;j<=hi[i];j++){
                if(i&(1<<j)){
                    sum+=a[j+1];
                }
            }
            if(sum>2*a[hi[i]+1]){
                ans++;
            }
        }
    }
    cout<<ans%P;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
