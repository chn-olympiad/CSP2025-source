#include <bits/stdc++.h>
using namespace std;
int n,m;
struct Node{
    int number;
    int points;
}a[1005];
bool cmp(Node x,Node y)
{
    return x.points>y.points;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i].points;
        a[i].number=i;
    }
    int b=a[1].points;
    sort(a+1,a+n*m+1,cmp);
    int cnt;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i].points==b)
        {
            cnt=i;
            break;
        }
    }
    int c=n*2;
    if(cnt%c==0)
    {
        cout<<cnt/c*2<<" "<<1;
    }
    else if(cnt%c<=n)
    {
        cout<<cnt/c*2+1<<" "<<cnt%c;
    }
    else
    {
        cout<<cnt/c*2+2<<" "<<2*n-cnt%c+1;
    }
    return 0;
}
