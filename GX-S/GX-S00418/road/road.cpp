#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll b[100040005]={0},f,g,sum=0,x,y,z;
struct road{ll c,d,e;}a[100005];
ll finder(ll c){return (b[c]==0)?c:finder(b[c]);}
bool cmp(road a,road b){return (a.e<b.e)?true:false;}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>x>>y>>z;
    int h=x;
    for(ll i=1;i<=y;++i)cin>>a[i].c>>a[i].d>>a[i].e;
    for(ll i=1;i<=z;++i)
    {
        cin>>f;
        for(ll j=1;j<=x;++j)
        {
            cin>>g;
        }
    }
    sort(a+1,a+y+1,cmp);
    int cnt=0;
    for(ll i=1;i<=y&&cnt<x-1;++i)
    {
        ll fc=finder(a[i].c),fd=finder(a[i].d);
        if(fc!=fd)
        {
            b[fc]=fd;
            ++cnt;
            sum+=a[i].e;
        }
    }
    cout<<sum;
    return 0;
}
