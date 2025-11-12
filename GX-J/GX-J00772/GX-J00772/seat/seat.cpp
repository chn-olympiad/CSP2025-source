#include <algorithm>
#include <iostream>
using namespace std;
int m,n,r,x[102];
bool cmp(int a,int b){return (a>b)?true:false;}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>r;
    x[1]=r;
    for(int i=2;i<=n*m;++i)cin>>x[i];
    sort(x+1,x+n*m+1,cmp);
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n&&j>0;++j)
    {
        if(x[(i-1)*n+j]==r)
        {
            int ans=(i%2==1)?j:n+1-j;
            cout<<i<<' '<<ans;
            return 0;
        }
    }
    return 0;
}
