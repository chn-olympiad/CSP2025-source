#include<iostream>
#include<queue>
#include<cstdio>
typedef long long ll;
using namespace std;
priority_queue<ll> c1,c2,c3;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll t;
    scanf("%lld",&t);
    while(t--){
        ll n,x,y,z,cnt1=0,cnt2=0,cnt3=0,ans=0;
        scanf("%lld",&n);
        for(ll i=1;i<=n;i++){
            scanf("%lld%lld%lld",&x,&y,&z);
            if(x>=y&&x>=z){
                ans+=x;
                c1.push(min(x-y,x-z)*-1);
                cnt1++;
            }
            else if(y>=x&&y>=z){
                ans+=y;
                c2.push(min(y-x,y-z)*-1);
                cnt2++;
            }
            else{
                ans+=z;
                c3.push(min(z-x,z-y)*-1);
                cnt3++;
            }
        }
        n/=2;
        while(cnt1>n){
            ll f=c1.top()*-1;
            c1.pop();
            ans-=f;
            cnt1--;
        }
        while(cnt2>n){
            ll f=c2.top()*-1;
            c2.pop();
            ans-=f;
            cnt2--;
        }
        while(cnt3>n){
            ll f=c3.top()*-1;
            c3.pop();
            ans-=f;
            cnt3--;
        }
        cout<<ans<<endl;
        while(!c1.empty()){
            c1.pop();
        }
        while(!c2.empty()){
            c2.pop();
        }
        while(!c3.empty()){
            c3.pop();
        }
    }
    return 0;
}
