#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
int n,m,a[105],b,cnt;
void solve()
{
    cin>>n>>m>>b;
    for(int i=1;i<n*m;i++)
    {
        cin>>a[i];
        if(a[i]>b)cnt++;
    }
    cnt++;
    int cnt1=cnt/n;
    int cnt2=cnt%n;
    if((cnt1%2==1)&&cnt2!=0)cout<<cnt1+1<<" "<<n-cnt2+1;
    else if((cnt1%2==1)&&cnt2==0)cout<<cnt1<<" "<<n;
    else if(cnt1%2!=1&&cnt2!=0)cout<<cnt1+1<<" "<<cnt2;
    else cout<<cnt1<<" "<<1;
}
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--)solve();
}
