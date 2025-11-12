#include <bits/stdc++.h>
using namespace std;
int a[10005];
int n,ans;
void check(int x,int y)
{
    int w=x-y;
    if (w<3)
    {
        return;
    }
    int maxx=-1,sum=0;
    for (int i=x;i<=y;i++)
    {
       maxx=max(maxx,a[i]);
       sum+=a[i];
    }
    if (sum>2*maxx )
    {

        ans++;
    }
    check(x,y-1);
    check(x+1,y);
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>a[i];
    }
    check(1,n);
    cout <<ans;
}
