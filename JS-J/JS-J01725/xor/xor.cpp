#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,a[N],b[N][2],k,sum,m,temp,y,maxx=-1;
bool check()
{
    for(int i=y+1;i<=m;i++)
        if(b[i][0]>b[y][1])
            return true;
    return false;
}
void dfs(int depth)
{
    if(check()==false)
    {
        maxx=max(maxx,depth);
        return ;
    }
    for(int i=y+1;i<=m;i++)
    {
        if(b[i][0]>b[y][1])
        {
            y=i;
            dfs(depth+1);
        }
    }
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        temp=i;
        sum=a[i];
        while(temp<=n)
        {
            if(sum==k)
            {
                b[++m][0]=i;
                b[m][1]=temp;
                break;
            }
            sum=(sum^a[++temp]);
        }
    }
    dfs(0);
    printf("%d",maxx);
    return 0;
}
