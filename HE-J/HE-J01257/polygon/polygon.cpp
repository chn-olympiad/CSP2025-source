#include <iostream>
#include <algorithm>
using namespace std;
int a[5005];
int wangye(int x,int y)
{
    int c=0;
    for(int i=x;i<=y;i++)
    {
        c+=a[i];
    }
    return c;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int m,k=0;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+m+1);
    for(int i=1;i<=m-2;i++)
    {
        for(int j=i+2;j<=m;j++)
        {
            if(wangye(i,j)>=2*a[j])
            {
                k++;
            }
        }
    }
    cout<<k*3/2;
}
