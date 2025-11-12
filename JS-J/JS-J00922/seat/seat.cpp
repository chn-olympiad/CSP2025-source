#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
int a[110];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n*m;i++)
    {
        scanf("%d",&a[i]);
        a[i]=-a[i];
        if(i==0)
        {
            r=a[i];
        }
    }
    sort(a,a+n*m);
    int x=0,y=0,fl=0;
    for(int i=0;i<n*m;i++)
    {
        if(a[i]==r)
        {
            printf("%d %d",y+1,x+1);
            return 0;
        }
        if(fl)
        {
            x--;
            if(x<0)
            {
                x++;
                y++;
                fl=0;
            }
        }
        else
        {
            x++;
            if(x==n)
            {
                x--;
                y++;
                fl=1;
            }
        }
    }
    return 0;
}
