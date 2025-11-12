#include<bits/stdc++.h>
using namespace std;
struct abab
{
    int num,weizhi;
}a[105];
bool cmp(abab x,abab y)
{
    return x.num>y.num;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i].num;
        a[i].weizhi=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int i,j,k;
    for(i=1;i<=n*m;i++)
        if(a[i].weizhi==1) break;
    int sum=0;
    for(j=1;j<=m;j++)
    {
        if(j%2)
        {
            for(k=1;k<=n;k++)
            {
                sum++;
                if(sum==i)
                {
                    cout<<j<<' '<<k;
                    return 0;
                }
            }
        }
        else
        {
            for(k=n;k>=1;k--)
            {
                sum++;
                if(sum==i)
                {
                    cout<<j<<' '<<k;
                    return 0;
                }
            }
        }
    }
    return 0;
}
