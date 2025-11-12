#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b,c;
    scanf("%d%d%d",&n,&m,&c);
    a[c]++;
    for(int i=2;i<=n*m;i++)
    {
        scanf("%d",&b);
        a[b]++;
    }
    int cnt=0;
    for(int i=100;i>=0;i--)
    {
        if(i==c)
            break;
        else if(a[i]!=0)
            cnt++;
    }
    if(cnt/n%2==0)
    {
        printf("%d %d",cnt/n+1,cnt%n+1);
    }
    else
        printf("%d %d",cnt/n+1,n-(cnt%n));
    return 0;
}
