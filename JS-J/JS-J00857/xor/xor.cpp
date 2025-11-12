#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ll n,k;
    ll a[500005];
    int l=1,r=1;
    cin >>n>>k;
    for(ll i=1;i<=n;i++){
        cin >>a[i];
    }
    while(1){
        cout<<l<<" "<<r<<endl;
        ll number=0;
        for(ll i=l;i<=r;i++){
            number^=a[i];
        }    
        if(number==k&&l<=n&&r<=n){
            cnt++;
            cout<<cnt<<endl;
            l=r+1;
            r=l;
            continue;
        }else{
            r++;
        }
        if(l>=n&&r>=n){
            cout<<cnt<<endl;
            return 0;
        }
        if(r>n&&l<=n){
            l++;
            r=l;
        }
          
    }
    return 0;
}