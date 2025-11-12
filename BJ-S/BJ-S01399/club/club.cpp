#include <cstdio>
#include <algorithm>
using namespace std;

int t;
struct node
{
    int x,y,z;
};
node a[100005];
int ans;
bool cmp(node x,node y)
{
    return (x.x > y.x);
}
void dfs(int step,int d,int x,int y,int z,int n,int k)
{
    if (step == n + 1)
    {
        if (x <= k && y <= k && z <= k)
        {
            ans = max(ans,d);
        }
        return ;
    }
    if (x + 1 <= k) dfs(step + 1,d + a[step].x,x + 1,y,z,n,k); // attend 1
    if (y + 1 <= k) dfs(step + 1,d + a[step].y,x,y + 1,z,n,k); // attend 2
    if (z + 1 <= k) dfs(step + 1,d + a[step].z,x,y,z + 1,n,k); // attend 3
    return ;
}
void c0dfs(int step,int d,int x,int y,int z,int n,int k)
{
    if (step == n + 1)
    {
        if (x <= k && y <= k)
        {
            ans = max(ans,d);
        }
        return ;
    }
    if (x + 1 <= k) c0dfs(step + 1,d + a[step].x,x + 1,y,z,n,k); // attend 1
    if (y + 1 <= k) c0dfs(step + 1,d + a[step].y,x,y + 1,z,n,k); // attend 2
    return ;
}
void all0dfs(int step,int d,int x,int y,int z,int n,int k)
{
    sort(a + 1,a + n + 1,cmp);
    int p = 0;
    for (int i = 1;i <= k;i++) p += a[i].x;
    ans = max(ans,p);
}

bool cmp2(node x,node y)
{
    if (x.x != y.x) return (x.x > y.x);
    if (x.y != y.y) return (x.y > y.y);
    return (x.z > y.z);
}
int zhengjie(int n)
{
    int k = 0,st = 1;
    sort(a + 1,a + n + 1,cmp2);
    for (int i = 1;i <= n;i++)
    {
        if (a[i].y > a[i].x) st = 2;
        if (a[i].z > a[i].y) st = 3;
        if (k >= n / 2)
        {
            st ++;
            k = 0;
        }
        if (st == 1) ans += a[i].x;
        if (st == 2) ans += a[i].y;
        if (st == 3) ans += a[i].z;
    }
    return 0;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while (t --)
    {
        ans = 0;
        bool all_0 = 1,twoall0 = 1;
        int n;
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
        {
            scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
            if (a[i].z != 0) all_0 = twoall0 = 0;
            if (a[i].y != 0) twoall0 = 0;
        }
        if (n <= 18) dfs(1,0,0,0,0,n,n / 2);
        else if (n > 18 && twoall0 == 1) all0dfs(1,0,0,0,0,n,n / 2);
        else if (n > 18 && all_0 == 1) c0dfs(1,0,0,0,0,n,n / 2);
        else zhengjie(n);
        printf("%d\n",ans);
    }
    return 0;
}
