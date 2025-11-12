#include<bits/stdc++.h>
using namespace std;
#define int long long
// 9:04 xu kong tiao shi 10min,wo shi ren?
int n,m,tgt;
int arr[114];
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=(n*m);i++)
    {
        cin>>arr[i];
    }
    tgt=arr[1];
    sort(arr+1,arr+1+(n*m),greater<int>());
    int nx=1,ny=1;
    for(int i=1;i<=(n*m);i++)
    {
        //cout<<arr[i]<<' ';
        if(arr[i]==tgt)
        {
            cout<<ny<<' '<<nx<<'\n';
            return 0;
        }
        if(ny%2==1)
        {
            nx++;
            if(nx>n)
            {
                ny++;
                nx=n;
            }
        }else
        {
            nx--;
            if(nx<1)
            {
                ny++;
                nx=1;
            }
        }
    }
    return 0;
}
