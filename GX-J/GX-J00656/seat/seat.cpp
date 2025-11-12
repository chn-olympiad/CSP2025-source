#include <bits/stdc++.h>
using namespace std;
int a[105];
int n,m;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    cout<<n<<m;
    int r=0;
    for(int i=1;i<=n*m;i++)
    {
        scanf("%d",&a[i]);
    }
    r=a[1];
    sort(a+1,a+n*m+1);
    int l=0;
    int h=0;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==r)
        {
            i=n*m-i+1;
            if(i%n==0)
            {
                l=i/n;
            }
            else
            {
                l=i/n+1;
            }
            if(l%2==0)
            {
                h=m-i%n+1;
            }
            else
            {
                h=i-(l-1)*m;
            }
            break;
        }
    }
    printf ("%d %d",l,h);
    return 0;
}

