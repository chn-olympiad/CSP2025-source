#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll n,t;
ll val1[N],val2[N],val3[N];
bool cmp(ll x,ll y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ll ans=0;
        cin>>n;
        ll sum1=0,sum2=0,sum3=0;
        ll cnt1=0,cnt2=0,cnt3=0;
        for(int i=1;i<=n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            if(a>b&&a>c) sum1+=a,cnt1++,val1[cnt1]=max(b,c)-a;
            if(b>a&&b>c) sum2+=b,cnt2++,val2[cnt2]=max(a,c)-b;
            if(c>a&&c>b) sum3+=c,cnt3++,val3[cnt3]=max(a,b)-c;
        }
        sort(val1+1,val1+1+cnt1,cmp);
        sort(val2+1,val2+1+cnt2,cmp);
        sort(val3+1,val3+1+cnt3,cmp);
        ans=sum1+sum2+sum3;
        if(cnt1>n/2){
            for(int i=1;cnt1>n/2;i++){
                ans+=val1[i];
                cnt1--;
            }
        }
        if(cnt2>n/2){
            for(int i=1;cnt2>n/2;i++){
                ans+=val2[i];
                cnt2--;
            }
        }
        if(cnt3>n/2){
            for(int i=1;cnt3>n/2;i++){
                ans+=val3[i];
                cnt3--;
            }
        }
        //printf("%lld %lld %lld\n",sum1,sum2,sum3);
        cout<<ans<<endl;
        //cout<<val1[1];
    }
    return 0;
}
