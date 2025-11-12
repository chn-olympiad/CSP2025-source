#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n,m,num,k;
int a[N],mp[105][105],cnt;
int read()
{
    int f=1,x=0;
    char c = getchar();
    while(!isdigit(c))
        f = c == '-' ? -1 : 1,c = getchar();
    while(isdigit(c))
        x = (x << 3) + (x << 1) + ( c ^ 48),c = getchar();
    return f*x;
}
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    n = read(),m = read();
    for(int i=1;i<=n*m;i++)
        a[i] = read();
    num = a[1];
    sort(a+1,a+n*m+1);
    k = lower_bound(a+1,a+n*m+1,num) - a;
    k = n*m - k + 1;
    for(int j=1;j<=m;j++)
    {
        if(j % 2)
            for(int i=1;i<=n;i++)
                mp[i][j] = ++cnt;
        else
            for(int i=n;i>=1;i--)
                mp[i][j] = ++cnt;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j] == k)
            {
                printf("%d %d\n",j,i);
                return 0;
            }    
        }
    }
    return 0;
}