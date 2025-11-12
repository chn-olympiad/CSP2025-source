#include <bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(int a,int b)
{
    return a>b;
}
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,s[105],cnt=0,num=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>s[i];
    int a=s[1];
    sort(s+1,s+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        num++;
        if(num>n)
        {
            cnt++;
            num=1;
        }
        if(s[i]==a)
        {
            if(cnt%2==1)
            {
                cout<<cnt+1<<' '<<n-(i-n*cnt)+1;
                break;
            }
            if(cnt%2==0)
            {
                cout<<cnt+1<<' '<<i-n*cnt;
                break;
            }
        }
    }
    return 0;
}
