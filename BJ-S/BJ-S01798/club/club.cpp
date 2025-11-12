#include<iostream>
#include<algorithm>
using namespace std;
struct node {int x,xi,y,d;} p[100001];
bool cmp(node x,node y) {return x.d > y.d;}
int cnt[5];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t; scanf("%d",&t);
    while(t--)
    {
        int n,a,b,c; scanf("%d",&n);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(a >= b && a >= c)
            {
                p[i].x = a; p[i].xi = 1;
                p[i].y = max(b,c);
            }
            else if(b >= a && b >= c)
            {
                p[i].x = b; p[i].xi = 2;
                p[i].y = max(a,c);
            }
            else
            {
                p[i].x = c; p[i].xi = 3;
                p[i].y = max(a,b);
            }
            p[i].d = p[i].x - p[i].y;
        }
        sort(p+1,p+1+n,cmp);
        cnt[1] = cnt[2] = cnt[3] = 0;
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            if(cnt[p[i].xi]+1 > n/2) ans += p[i].y;
            else {ans += p[i].x; cnt[p[i].xi]++;}
        }
        printf("%d\n",ans);
    }
    return 0;
}
