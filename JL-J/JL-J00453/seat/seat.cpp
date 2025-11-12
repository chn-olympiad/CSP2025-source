#include<bits/stdc++.h>
using namespace std;
int a[200];
int main()
{
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[(i-1)*n+j]);
        }
    }
    int tmp=a[1];
    sort(a+1,a+n*m+1);
    int x=1,y=1,k=1,fl=0;
    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--)
        {
            //cout<<x<<' '<<y<<endl;
            if(a[(i-1)*n+j]==tmp)
            {
                printf("%d %d\n",y,x);
                return 0;
            }
            if(k==n)
            {
                k=1;
                if(y%2==1)
                {
                    x=n;
                    y++;
                    fl=1;
                }
                else
                {
                    x=1;
                    y++;
                    fl=0;
                }
                //cout<<endl;
            }
            else
            {
                //cout<<x<<endl;
                if(fl)x--;
                else x++;
                k++;
            }
        }
    }
    return 0;
}
