#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[15],n;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    if(n==3){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        if(a[1]+a[2]>a[3]) cout<<1;
        else cout<<0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<0;
    return 0;
}

