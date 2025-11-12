#include <bits/stdc++.h>
using namespace std;
int a[1010];
int cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in", "r",stdin);
    freopen("seat.out", "w",stdout);
    int n,m;
    cin>>n>>m;
    int r;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+n*m+1,cmp);
    int flag=0;
    int cnt=0;
    for(int i=1,j=1;j<=m;)
    {
        cnt++;
        if(a[cnt]==r)
        {
            cout<<j<<' '<<i;
            return 0;
        }
        if(flag==0)
        {
            if(i==n)
            {
                j++;
                flag=1;
                continue;
            }
            i++;
        }else
        {
            if(i==1)
            {
                j++;
                flag=0;
                continue;
            }
            i--;
        }
    }
    return 0;
}
