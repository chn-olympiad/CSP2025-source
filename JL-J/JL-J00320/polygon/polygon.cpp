#include<bits/stdc++.h>
using namespace std;
int n,p=998244353,a[5005],ans,r[5005];
inline int R(int x){
    return x>5000?5001:x;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>r[i];
    sort(r,r+n);
    a[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=r[i]+1;j<=5001;j++)
            (ans += a[j]) %= p;
        for(int j=5001;j>=0;j--)
            (a[R(j+r[i])] += a[j]) %= p;
    }
    cout<<ans;
}
