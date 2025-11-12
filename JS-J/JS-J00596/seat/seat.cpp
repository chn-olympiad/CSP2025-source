#include <bits/stdc++.h>
using namespace std;
const int M=100+10;
const int Mi[]={-1,1};
struct Node
{
    int val;
    int id;
    bool operator<(const Node& a) const { return val>a.val; }
};
int n,m;
Node a[M];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i)
    {
        cin>>a[i].val;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1);
    int x=1,y=1,cnt=1;
    while(a[cnt].id!=1)
    {
        y+=Mi[x%2];
        if(y<1 || y>m)
        {
            x++;
            y=(x%2?1:m);
        }
        cnt++;
    }
    cout<<x<<' '<<y<<endl;
    return 0;
}
