#include<bits/stdc++.h>
using namespace std;
const int N=5000+10;
int a[N];
int n;int cnt;
bool cmp(int x,int y) {
    return x>y;
}
void solve()
{
    if(n<3) cout<<0<<'\n';
    else
    {
        sort(a+1,a+n+1,cmp);
        if(a[2]+a[3]>a[1]) cout<<"1\n";
        else cout<<"0\n";
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {cin>>a[i];if(a[i]==1) cnt++;}
    if(cnt==n)
    {
        int m=n-1;
        cout<<m*(m-1)/2;
        return 0;
    }
    else
    {
        solve();
    }
    return 0;
}