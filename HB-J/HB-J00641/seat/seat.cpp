#include <bits/stdc++.h>
using namespace std;
struct mzl
{
    int o,p;
}a[1000];
int cmp(mzl x,mzl y)
{
    if(x.p>y.p)
        return true;
    else
        return false;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        a[i].o=i;
        cin>>a[i].p;
    }
    int jk=a[1].o;
    sort(a+1,a+n*m+1,cmp);
    int flag=0;
    for(int i=1;i<=n*m;i++)
    {
        if(jk==a[i].o)
        {
            flag=i;
            break;
        }
    }
    int q=0;
    if(flag%n!=0)
    {
        q=flag/n+1;
    }
    else
    {
        q=flag/n;
    }
    int k=0;
    if(flag%n==0)
    {
        k=n;
    }
    else
    {
        k=flag%n;
    }
    if(q%2==0)
    {
        cout<<q<<" "<<n-k+1;
    }

    else
    {
        cout<<q<<" "<<k;
    }
    return 0;
}
