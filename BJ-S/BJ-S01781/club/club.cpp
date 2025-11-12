#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[100005],b[100005],c[100005];
ll T;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        ll ans=0;
        vector<ll> x,y,z;
        for(ll i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            ans+=max(a[i],max(b[i],c[i]));
            if(a[i]>max(b[i],c[i])){
                x.push_back(a[i]-max(b[i],c[i]));
            }
            else if(b[i]>max(a[i],c[i])){
                y.push_back(b[i]-max(a[i],c[i]));
            }
            else{
                z.push_back(c[i]-max(a[i],b[i]));
            }
        }
        if(x.size()>(n/2)){
            sort(x.begin(),x.end());
            for(int i=0;i<x.size()-(n/2);i++){
                ans=ans-x[i];
            }
        }
        else if(y.size()>(n/2)){
            sort(y.begin(),y.end());
            for(int i=0;i<y.size()-(n/2);i++){
                ans=ans-y[i];
            }
        }
        else if(z.size()>(n/2)){
            sort(z.begin(),z.end());
            for(int i=0;i<z.size()-(n/2);i++){
                ans=ans-z[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
