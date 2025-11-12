#include<bits/stdc++.h>
using namespace std;
int t,n,maxn;
int n1,n2,n3;
struct node
{
    int x1,x2,x3;
}a[100005];
void dfs(int step,int sum)
{
    if(step>n)
    {
        if(n1<=n/2&&n2<=n/2&&n3<=n/2)
        {
            maxn=max(maxn,sum);
        }
        return;
    }
    n1++;
    dfs(step+1,sum+a[step].x1);
    n1--;
    n2++;
    dfs(step+1,sum+a[step].x2);
    n2--;
    n3++;
    dfs(step+1,sum+a[step].x3);
    n3--;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        n1=n2=n3=maxn=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d %d",&a[i].x1,&a[i].x2,&a[i].x3);
        }
        dfs(1,0);
        printf("%d\n",maxn);
    }
    return 0;
}
