#include <bits/stdc++.h>
using namespace std;
int n,a[5010];
long long ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    if (n<=3){
        if (n<3) cout<<0;
        else {
            int x=a[n];
            if (a[1]+a[2]+a[3]>x*2) cout<<1;
            else cout<<0;
        }
    }
    else cout<<0;
    return 0;
}
