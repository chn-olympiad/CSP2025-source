#include <bits/stdc++.h>
using namespace std;
int n,m,q,w;
struct seat
{
    int score;
    int id;
}a[105];

bool cmp(seat a,seat b)
{
    return a.score > b.score;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
    {
        cin>>a[i].score;
        a[i].id=i;
    }
    sort(a,a+(n*m)+1,cmp);
    for (int i=1;i<=n*m;i++)
    {
        if (a[i].id==1)
        {
            q=i+1;
        }
    }
    //cout<<q<<endl;
    if (q<=n)
        cout<<1<<" ";
    else cout<<q/n+1;
    if (q==n)
        cout<<q;
    else cout<<q%n;
    return 0;
}
