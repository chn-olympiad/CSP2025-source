#include<bits/stdc++.h>
using namespace std;
int n,m,flag;
int a[169];
int ans[13][13];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    flag=a[1];
    sort(a+1,a+n*m+1);
    reverse(a+1,a+n*m+1);
    for(int i=1;i<=m;i++)
    {
        if(i%2==0)
        {
            int k=1;
            for(int j=n;j>=1;j--)
            {
                ans[i][k]=a[(i-1)*n+j];
                k++;
            }
        }
        if(i%2==1)
        {
            for(int j=1;j<=n;j++)
            {
                ans[i][j]=a[(i-1)*n+j];
            }
        }
    }
    for(int i=1;i<=m;i++)
    {

        for(int j=1;j<=n;j++)
        {

            if(ans[i][j]==flag)
            {

                cout<<i<<" "<<j;
            }
        }
    }
    return 0;
}
