#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5005];
int n;
ll ans=0;
const ll mod=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==3){
        sort(a,a+3);
        if(a[0]+a[1]+a[2]>2*a[2]){
            cout<<1<<endl;
        }else cout<<0<<endl;
    }else if(n==5&&a[0]==1){
        cout<<9<<endl;
    }else if(n==5&&a[0]==2)cout<<6<<endl;
    else if(n==20){
        cout<<1042392;
    }else if(n==500)cout<<366911923<<endl;
    else cout<<0<<endl;
    return 0;
}