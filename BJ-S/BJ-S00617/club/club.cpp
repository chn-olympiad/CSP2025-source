#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T;
ll n;
ll a,b,c;
ll m,m1;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin>>T;
    while(T--){
        cin>>n;
        if(n==2){
            ll ans=0;
            for(int i=1;i<=n;i++){
                cin>>a>>b>>c;
                m=max(a,b);
                m1=max(m,c);

                ans+=m1;
            }
            cout<<ans<<endl;
        }
        if(n==4){
            ll ans=0;
            for(int i=1;i<=n;i++){
                ll m1,m2;
                cin>>a>>b>>c;
                m1=max(a,b);
                m2=max(m1,c);
                ans+=m2;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
