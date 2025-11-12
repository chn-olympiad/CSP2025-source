#include <iostream>
#include <algorithm>
using namespace std;
int t,n;
unsigned long long ans;
struct node
{
    int a,b,c;
}a[100005];
bool cmp(node x,node y)
{
    if (x.a>x.b)
    {
        if (y.a>y.b)
            return x.a>y.a;
        else
            return true;
    }
    else
    {
        if (y.a>y.b)
            return false;
        else
            return x.b>y.b;
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i=1;i<=n;i++)
            cin >> a[i].a >> a[i].b >> a[i].c;
        sort(a+1,a+n+1,cmp);
        int used=0;
        int i=1;
        for (;used<n/2;i++,used++)
            ans+=a[i].a;
        used=0;
        for (;used<n/2;i++,used++)
            ans+=a[i].b;
        cout << ans << endl;
        ans=0;
    }
    return 0;
}
