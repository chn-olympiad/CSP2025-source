#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
ll t,n,temp,temp2;
ll a[N][4];
int check[4];
int main(){
    ios::sync_with_stdio;
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ll ans1=0,ans2=0;
        cin>>n;
        temp=n/2;
        temp2=n/2-1;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        for(int i=1;i<=n;i++){
            ll k=0;
            if(check[1]<temp){
                k=max(k,a[i][1]);
            }
            if(check[2]<temp){
                k=max(k,a[i][2]);
            }
            if(check[3]<temp){
                k=max(k,a[i][3]);
            }
            if(k==a[i][1]){
                check[1]++;
            }
            else if(k==a[i][2]){
                check[2]++;
            }
            else if(k==a[i][3]){
                check[3]++;
            }
            ans1+=k;
        }
        for(int i=1;i<=4;i++){
            check[i]=0;
        }
        for(int i=n;i>=1;i--){
            ll k=0;
            if(check[1]<temp){
                k=max(k,a[i][1]);
            }
            if(check[2]<temp){
                k=max(k,a[i][2]);
            }
            if(check[3]<temp){
                k=max(k,a[i][3]);
            }
            if(k==a[i][1]){
                check[1]++;
            }
            else if(k==a[i][2]){
                check[2]++;
            }
            else if(k==a[i][3]){
                check[3]++;
            }
            ans2+=k;
        }
        cout<<max(ans1,ans2)<<"\n";
    }
    return 0;
}
