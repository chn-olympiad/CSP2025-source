#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n;
const ll N=1010100;
ll a[N][5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ll mx=0;
        ll sum=0;
        cin>>n;
        ll m=n/2;
        ll d[5]={0,0,0};
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
            for(ll i=1;i<=n;i++){
                mx+=max(max(a[i][1],a[i][2]),a[i][3]);
                if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
                    d[1]++;
                }else if(a[i][1]<a[i][2]&&a[i][2]>a[i][3]){
                    d[2]++;
                }else if(a[i][3]>a[i][2]&&a[i][1]<a[i][3]){
                    d[3]++;
                }
            }
            if(d[1]<=m&&d[2]<m&&d[3]<m) cout<<mx<<endl;
            else{
                    ll mx=0;
                for(ll k=1;k<n;k++)
            for(ll i=1;i<=3;i++){
                for(ll j=1;j<=3;j++){
                    if(i!=j){
                        if(a[k][i]+a[k+1][j]>mx){
                            mx=a[k][i]+a[k+1][j];
                        }
                    }
                }
            }
        cout<<mx<<endl;
            }
    }
    return 0;
}
