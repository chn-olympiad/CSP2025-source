#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,cnt=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>a[1])
            cnt++;
    }
    int x=cnt/n;
    printf("%d ",x+1);
    if(x&1)
        printf("%d\n",n-cnt%n);
    else
        printf("%d\n",cnt%n+1);
    return 0;
}
