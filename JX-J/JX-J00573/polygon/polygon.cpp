#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
void DFS(int m,int now,int ma,int sum)
{
    if(now>n)
    {
        if(sum>2*ma&&m>=3) ans++,ans%=998244353;
        return;
    }
    DFS(m+1,now+1,max(ma,a[now]),sum+a[now]);
    DFS(m,now+1,ma,sum);
    return;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<3)
    {
        cout<<'0';
        return 0;
    }
    else if(n==3)
    {
        if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]) cout<<'1';
        else cout<<'0';
        return 0;
    }
    else
    {
        DFS(0,1,INT_MIN,0);
        cout<<ans;
    }
    return 0;
}
