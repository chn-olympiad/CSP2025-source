#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int s;
pair<int,int>a[N];// a for score,b for R
int up(int x,int y)
{
    if(x%y==0) return x/y;
    return x/y+1;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i].first,a[i].second=i;
    sort(a+1,a+n*m+1,greater<pair<int,int> >());
    // for(int i=1;i<=n*m;i++)
    // {
    //     printf("a[%d]:%d,%d\n",i,a[i].first,a[i].second);
    // }
    for(int i=1;i<=n*m;i++)
    {
        if(a[i].second==1)
        
        {
            int s=i;
            int si=up(s,n);
            if(si%2) cout<<si<<" "<<s-(si-1)*n;
            else cout<<si<<" "<<(n+1)-(s-(si-1)*n);
            return 0;
        }
    }
    return 0;
}