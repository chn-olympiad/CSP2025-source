#include<bits/stdc++.h>
using namespace std;

const int Mod(998244353);
unsigned long long a[5005];

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,ans(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int x=max(a[1],max(a[2],a[3]));
    if(2*a<a[1]+a[2]+a[3])ans++;
    cout<<ans;
    return 0;
}


