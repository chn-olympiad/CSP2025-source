#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n,m;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m; a.resize(n*m);
    for(auto &p:a) cin>>p;
    int tmp=a[0],r,c;
    sort(a.begin(),a.end());
    tmp=a.end()-lower_bound(a.begin(),a.end(),tmp)-1;
    r=tmp/n+1; c=tmp%n;
    if(r&1) c++;
    else c=n-c;
    cout<<r<<' '<<c;
    return 0;
}
