#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,r,f=0,cnt=1,x;
ll arr[110],a[15][15];
bool cmp(ll x,ll y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>arr[i];
    r=arr[1];
    sort(arr+1,arr+1+n*m,cmp);
    while(cnt<=n*m)
    {
        x++;
        if(f==0)
        {
            f=1;
            for(ll i=1;i<=n;i++)
            {
                if(arr[cnt]==r)
                {
                    cout<<x<<" "<<i;
                    return 0;
                }
                a[i][x]=arr[cnt];
                cnt++;
            }
        }
        else
        {
            f=0;
            for(ll i=n;i>=1;i--)
            {
                if(arr[cnt]==r)
                {
                    cout<<x<<" "<<i;
                    return 0;
                }
                a[i][x]=arr[cnt];
                cnt++;
            }
        }
    }
    /*for(ll i=1;i<=n;i++)
    {

        for(ll j=1;j<=m;j++)
        {

            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return 0;
}
/*
4 5
1 2 3 342 236 423 867 9468 7875 8347  326 892369 475843 758832748 7436864379 34676475 6783697823 526798734 489328 6327
*/
