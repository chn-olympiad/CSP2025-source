#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m,s;
struct node
{
    int f,id;
    friend bool operator < (node a,node b)
    {
        return a.f>b.f;
    }
} d[1000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    scanf("%d %d",&n,&m);
    s=n*m;
    for(int i=1; i<=s; i++)
    {
        scanf("%d",&d[i].f);
        d[i].id=i;
    }
    sort(d+1,d+1+s);
    //for(int i=1;i<=s;i++)
    //    printf("%d %d\n",d[i].f,d[i].id);
    for(int i=1; i<=s; i++)
    {
        if(d[i].id==1)
        {
            int l,r;
            if(i%n==0)
            {
                l=i/n;
                if(l%2==0)
                    r=1;
                else
                    r=n;
            }
            else
            {
                l=i/n+1;
                if(l%2==0)
                    r=n+1-i%n;
                else
                    r=i%n;
            }
            printf("%d %d",l,r);
            break;
        }
    }
    return 0;
}
