#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("seat.in","r",stdin);
    // freopen("seat.out","w",stdout);
    int n,m,po;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    po=a[1];
    sort(a+1,a+n*m+1);
    reverse(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++)
    {
        if(po==a[i])
        {
            po=i;
            break;
        }
    }
    int c=1,r=1,f=1,ok=0;
    for(int i=2;i<=po;i++)
    {
        if(r==n&&ok==0)
        {
            f=-1;
            c++;
            ok=1;
        }
        else if(r==1&&c!=1&&ok==0)
        {
            f=1;
            c++;
            ok=1;
        }
        else
        {
            r+=f;
            ok=0;
        }
    }
    cout<<c<<' '<<r<<'\n';
    return 0;
}