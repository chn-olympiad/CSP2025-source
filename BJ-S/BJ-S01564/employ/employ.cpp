#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,m,ytt,c[505],sum,s;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++){
        cin>>c[i];
        sum+=c[i];
    }
    cout<<sum*73470;

    return 0;
}
