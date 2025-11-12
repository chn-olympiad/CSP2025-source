#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T,n,x,y,z,sum,a[N][3],c[N],k[3];
priority_queue <int> q;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++) scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        sum = k[0] = k[1] = k[2] = 0;
        for(int i = 1;i <= n;i++)
        {
            int maxn = max(a[i][0],max(a[i][1],a[i][2]));
            if(maxn == a[i][0]) c[i] = 0;
            else if(maxn == a[i][1]) c[i] = 1;
            else c[i] = 2;
            sum += a[i][c[i]],k[c[i]]++;
        }
        x = max(k[0],max(k[1],k[2]));
        if(x == k[0]) x = 0;
        else if(x == k[1]) x = 1;
        else x = 2;
        y = (x ? 0 : 1),z = (x == 2 ? 1 : 2);
        while(!q.empty()) q.pop();
        for(int i = 1;i <= n;i++) if(c[i] == x) q.push(max(a[i][y],a[i][z]) - a[i][x]);
        while(k[x] > n / 2) sum += q.top(),q.pop(),k[x]--;
        printf("%d\n",sum);
    }
    return 0;
}