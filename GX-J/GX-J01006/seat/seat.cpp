#include<bits/stdc++.h>
using namespace std;
long long a[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int b[m*n+1]={0},c[m*n+1]={0};
    for(int i=1;i<=n*m;i++)
    {
       cin>>a[i];
    }
    int g=a[1],l=m*n;
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i%2==1)
            {
                b[l]=i;
                c[l]=j;
                if(a[l]==g)
                {

                    cout<<b[l]<<" "<<c[l];
                    return 0;
                }
                l--;
            }
            else if(i%2==0)
            {
                b[l]=i;
                c[l]=m-j+1;
                if(a[l]==g)
                {

                    cout<<b[l]<<" "<<c[l];
                    return 0;
                }
                l--;
            }
        }
    }
    return 0;
}
