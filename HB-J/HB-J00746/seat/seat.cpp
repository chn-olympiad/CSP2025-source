#include <iostream>
#include <algorithm>
using namespace std;
int n,m,x,c,r;
struct student
{
    int sc,id;
} a[105];
bool cmp(student x,student y)
{
    return x.sc>y.sc;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++)
    {
        cin >> a[i].sc;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i].id==1)
        {
            x=i;
            break;
        }
    }
    c=(x+n-1)/n;
    r=x%n;
    if(r==0)
    {
        r=n;
    }
    if(c%2==0)
    {
        r=n-r+1;
    }
    cout << c << " " << r;
    return 0;
}
