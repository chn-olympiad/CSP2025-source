#include <bits/stdc++.h>
using namespace std;

long long n,m;
struct node
{
    int f;
    int id;
    int nid;
}a[105];

bool cmp(node a,node b)
{
    return a.f>b.f;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i].f;
        a[i].id=i;
    }
    sort(a+1,a+m*n+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        a[i].nid=i;
        if(a[i].id==1)
        {
            long long l=(a[i].nid+n-1)/n;
            cout<<l<<" ";
            if(l%2==0)
            {
                long long c=a[i].nid-(l-1)*n;
                cout<<n-c+1<<endl;
            }
            if(l%2==1)
            {
                long long c=a[i].nid-(l-1)*n;
                cout<<c<<endl;
            }
            break;
        }
    }
    return 0;
}
