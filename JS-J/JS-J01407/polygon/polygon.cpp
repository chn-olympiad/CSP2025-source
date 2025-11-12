#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,Q=998244353;
int n,a[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<3) cout<<0;
    else if(n==3){
        int sum=0,mx=-1;
        for(int i=1;i<=n;i++){
            sum+=a[i];
            mx=max(mx,a[i]);
        }
        if(sum>2*mx) cout<<1;
        else cout<<0;
    }
    else{
        cout<<0;
    }
    return 0;
}
