#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int mod=998244353,N=5005;
int n,a[N];
namespace n_little_3
{
    void main()
    {
        cin>>a[1]>>a[2]>>a[3];
        int A=max(a[1],max(a[2],a[3])),cnt;
        if(a[1]+a[3]+a[2]>2*A)cnt++;
        cout<<cnt;
    }
}
int dfs(int x)
{
    if(x==3)
    {
        if(a[1]+a[3]+a[2]>2*a[3])return 1;
        return 0;
    }
    if(x==4)
    {
        int cnt=dfs(3);
        if(a[1]+a[2]+a[4]>2*a[4])cnt++;
        if(a[1]+a[3]+a[4]>2*a[4])cnt++;
        if(a[2]+a[3]+a[4]>2*a[4])cnt++;
        if(a[1]+a[2]+a[3]+a[4]>2*a[4])cnt++;
        return cnt;
    }
    if(x==5)
    {
        int cnt=dfs(4);
        if(a[1]+a[2]+a[5]>2*a[5])cnt++;
        if(a[1]+a[3]+a[5]>2*a[5])cnt++;
        if(a[1]+a[4]+a[5]>2*a[5])cnt++;
        if(a[2]+a[3]+a[5]>2*a[5])cnt++;
        if(a[4]+a[2]+a[5]>2*a[5])cnt++;
        if(a[3]+a[5]+a[5]>2*a[5])cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]>2*a[5])cnt++;
        if(a[1]+a[2]+a[3]+a[5]>2*a[5])cnt++;
        if(a[1]+a[2]+a[4]+a[5]>2*a[5])cnt++;
        if(a[1]+a[3]+a[4]+a[5]>2*a[5])cnt++;
        if(a[2]+a[3]+a[4]+a[5]>2*a[5])cnt++;
        return cnt;
    }
    if(x==6)
    {
        int cnt=dfs(5);
        if(a[1]+a[2]+a[6]>2*a[6])cnt++;
        if(a[1]+a[3]+a[6]>2*a[6])cnt++;
        if(a[1]+a[4]+a[6]>2*a[6])cnt++;
        if(a[1]+a[5]+a[6]>2*a[6])cnt++;
        if(a[2]+a[3]+a[6]>2*a[6])cnt++;
        if(a[4]+a[2]+a[6]>2*a[6])cnt++;
        if(a[4]+a[2]+a[6]>2*a[6])cnt++;
        if(a[3]+a[4]+a[6]>2*a[6])cnt++;
        if(a[3]+a[5]+a[6]>2*a[6])cnt++;
        if(a[4]+a[5]+a[6]>2*a[6])cnt++;
        if(a[1]+a[2]+a[3]+a[6]>2*a[6])cnt++;
        if(a[1]+a[2]+a[4]+a[6]>2*a[6])cnt++;
        if(a[1]+a[2]+a[5]+a[6]>2*a[6])cnt++;
        if(a[1]+a[3]+a[4]+a[6]>2*a[6])cnt++;
        if(a[1]+a[3]+a[5]+a[6]>2*a[6])cnt++;
        if(a[1]+a[4]+a[5]+a[6]>2*a[6])cnt++;
        if(a[2]+a[3]+a[4]+a[6]>2*a[6])cnt++;
        if(a[2]+a[3]+a[5]+a[6]>2*a[6])cnt++;
        if(a[2]+a[4]+a[5]+a[6]>2*a[6])cnt++;
        if(a[3]+a[4]+a[5]+a[6]>2*a[6])cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[6]>2*a[6])cnt++;
        if(a[1]+a[2]+a[3]+a[5]+a[6]>2*a[6])cnt++;
        if(a[1]+a[2]+a[5]+a[4]+a[6]>2*a[6])cnt++;
        if(a[1]+a[5]+a[3]+a[4]+a[6]>2*a[6])cnt++;
        if(a[5]+a[2]+a[3]+a[4]+a[6]>2*a[6])cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>a[6]*2)cnt++;
        return cnt;
    }
    if(x==7)
    {
        int cnt=dfs(6);
        if(a[1]+a[2]+a[7]>2*a[7])cnt++;
        if(a[1]+a[3]+a[7]>2*a[7])cnt++;
        if(a[1]+a[4]+a[7]>2*a[7])cnt++;
        if(a[1]+a[5]+a[7]>2*a[7])cnt++;
        if(a[1]+a[6]+a[7]>2*a[7])cnt++;
        if(a[2]+a[3]+a[7]>2*a[7])cnt++;
        if(a[4]+a[2]+a[7]>2*a[7])cnt++;
        if(a[5]+a[2]+a[7]>2*a[7])cnt++;
        if(a[6]+a[2]+a[7]>2*a[7])cnt++;
        if(a[3]+a[4]+a[7]>2*a[7])cnt++;
        if(a[3]+a[5]+a[7]>2*a[7])cnt++;
        if(a[3]+a[6]+a[7]>2*a[7])cnt++;
        if(a[4]+a[5]+a[7]>2*a[7])cnt++;
        if(a[4]+a[6]+a[7]>2*a[7])cnt++;
        if(a[5]+a[6]+a[7]>2*a[7])cnt++;
        if(a[1]+a[2]+a[3]+a[7]>2*a[7])cnt++;
        if(a[1]+a[2]+a[4]+a[7]>2*a[7])cnt++;
        if(a[1]+a[2]+a[5]+a[7]>2*a[7])cnt++;
        if(a[1]+a[2]+a[6]+a[7]>2*a[7])cnt++;
        if(a[1]+a[4]+a[3]+a[7]>2*a[7])cnt++;
        if(a[1]+a[5]+a[3]+a[7]>2*a[7])cnt++;
        if(a[1]+a[6]+a[3]+a[7]>2*a[7])cnt++;
        if(a[1]+a[4]+a[5]+a[7]>2*a[7])cnt++;
        if(a[1]+a[4]+a[6]+a[7]>2*a[7])cnt++;
        if(a[1]+a[5]+a[6]+a[7]>2*a[7])cnt++;
        if(a[4]+a[2]+a[3]+a[7]>2*a[7])cnt++;
        if(a[5]+a[2]+a[3]+a[7]>2*a[7])cnt++;
        if(a[6]+a[2]+a[3]+a[7]>2*a[7])cnt++;
        if(a[5]+a[2]+a[4]+a[7]>2*a[7])cnt++;
        if(a[6]+a[2]+a[4]+a[7]>2*a[7])cnt++;
        if(a[5]+a[4]+a[3]+a[7]>2*a[7])cnt++;
        if(a[6]+a[4]+a[3]+a[7]>2*a[7])cnt++;
        if(a[6]+a[5]+a[3]+a[7]>2*a[7])cnt++;
        if(a[6]+a[5]+a[4]+a[7]>2*a[7])cnt++;
        if(a[6]+a[2]+a[5]+a[7]>2*a[7])cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[7]>2*a[7])cnt++;
        if(a[1]+a[2]+a[3]+a[5]+a[7]>2*a[7])cnt++;
        if(a[1]+a[2]+a[3]+a[6]+a[7]>2*a[7])cnt++;
        if(a[1]+a[2]+a[4]+a[5]+a[7]>2*a[7])cnt++;
        if(a[1]+a[2]+a[4]+a[6]+a[7]>2*a[7])cnt++;
        if(a[1]+a[2]+a[5]+a[6]+a[7]>2*a[7])cnt++;
        if(a[1]+a[3]+a[4]+a[5]+a[7]>2*a[7])cnt++;
        if(a[1]+a[3]+a[4]+a[6]+a[7]>2*a[7])cnt++;
        if(a[1]+a[3]+a[5]+a[6]+a[7]>2*a[7])cnt++;
        if(a[1]+a[4]+a[5]+a[6]+a[7]>2*a[7])cnt++;
        if(a[2]+a[3]+a[4]+a[5]+a[7]>2*a[7])cnt++;
        if(a[2]+a[3]+a[4]+a[6]+a[7]>2*a[7])cnt++;
        if(a[2]+a[3]+a[5]+a[6]+a[7]>2*a[7])cnt++;
        if(a[2]+a[4]+a[5]+a[6]+a[7]>2*a[7])cnt++;
        if(a[3]+a[4]+a[5]+a[6]+a[7]>2*a[7])cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[7]>2*a[7])cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[6]+a[7]>2*a[7])cnt++;
        if(a[1]+a[2]+a[3]+a[6]+a[5]+a[7]>2*a[7])cnt++;
        if(a[1]+a[2]+a[6]+a[4]+a[5]+a[7]>2*a[7])cnt++;
        if(a[1]+a[6]+a[3]+a[4]+a[5]+a[7]>2*a[7])cnt++;
        if(a[6]+a[2]+a[3]+a[4]+a[5]+a[7]>2*a[7])cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>2*a[7])cnt++;
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    cout<<dfs(n);
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--)solve();
}
