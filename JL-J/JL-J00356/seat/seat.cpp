#include<bits/stdc++.h>

using namespace std;
//100pts
struct node
{
    int id,x;
} a[105];
int n,m;
bool f=0;

bool cmp(node a,node b)
{
    return a.x > b.x;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
    {
        scanf("%d",&a[i].x);
        a[i].id = i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        int j = i / n + (i % n ? 1 : 0);
        int k = i % n + (i % n ? 0 : n);
        if(j % 2 == 0)
        {
            k = n - k + 1;
        }
        if(a[i].id == 1)
        {
            printf("%d %d",j,k);
            return 0;
        }
    }


    return 0;
}
