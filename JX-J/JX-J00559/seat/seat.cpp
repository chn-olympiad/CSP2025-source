#include <bits/stdc++.h>
using namespace std;
struct seat{
    int f;
    int id;
}a[1010];
bool cmp(seat x,seat y)
{
    return x.f>y.f;
}
int main()
{
    freopen("seat.in",r,stdin);
    freopen("seat.out",w,stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i].f;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int num;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i].id==1)
        {
            num=i;
            break;
        }
    }
    cout<<num/n+1<<" ";
    if(num%n==0)
    {
        cout<<m;
    }
    else
    {
        cout<<num%n;
    }
    return 0;
}
