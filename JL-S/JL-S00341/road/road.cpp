#include<bits/stdc++.h>
// #define int long long
using namespace std;
int n , m , k , cnt , c[12] , a[12][10010] , fa[20010];
struct node
{
    int u , v , w;
    bool operator < (const node &qwq) const 
    {
        return w < qwq.w;
    }
}tmp[50000010] , tmp2[10000010];
int get_fa(int x) {return x == fa[x] ? x : fa[x] = get_fa(fa[x]);}
bool flagqqq = true;
void solveA()
{
    int ans = 1000000000000000000ll;
    // printf("here?");
    for(int i = 1 ; i <= k ; i ++)
    {
        for(int j = 1 ; j <= n ; j ++)
        {
            for(int jj = 1 ; jj <= n ; jj ++)
            {
                if(jj == j) continue;
                tmp[++ cnt] = {j , jj , a[i][j] + a[i][jj]};
                // tmp[++ cnt] = {jj , j , a[i][j] + a[i][jj]};
            }
        }
    }
    
    for(int i = 1 ; i <= n + k ; i ++) fa[i] = i;
    int Q = 0;
    int cnt2 = 0;
    long long sum = 0;
    int num = 1;
    // memcpy(tmp2 , tmp , sizeof(tmp));
    

    
    sort(tmp + 1 , tmp + cnt2 + cnt + 1);
    int oknum = 1;
    for(int i = 1 ; i <= cnt2 + cnt ; i ++)
    {
        int u = tmp[i].u , v = tmp[i].v , w = tmp[i].w;
        int uu = get_fa(u) , vv = get_fa(v);
        if(uu == vv) continue;
        fa[uu] = vv;
        oknum ++;
        sum += w * 1ll;
        // printf("u:%d v:%d w:%d sum:%d oknum:%d\n" , u , v , w , sum , oknum);
        if(oknum == n) break;
    }
    // printf("sum**********%d %d\n" , sum , Q);
    printf("%lld\n" , sum);
}
signed main()
{
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    scanf("%d%d%d" , &n , &m , &k);
    for(int i = 1 , u , v , w ; i <= m ; i ++) scanf("%d%d%d" , &u , &v , &w) , tmp[++ cnt] = {u , v , w};// , tmp[++ cnt] = {v , u , w};
    // sort(tmp + 1 , tmp + cnt + 1);
    // printf("no what the fuck\n");
    for(int i = 1 , x ; i <= k ; i ++)
    {
        scanf("%d" , &x);
        c[i] = x;
        // if(x != 0) flagqqq = false;
        flagqqq &= (c[i] == 0);
        for(int j = 1 ; j <= n ; j ++) scanf("%d" , &a[i][j]);// , printf("j:%d\n" , j);
        // printf("****%d" , i);
    }
    if(flagqqq == true)
    {
        solveA();
        return 0;
    }
    // printf("fuck here????");
    long long ans = 1000000000000000000ll;
    for(int Q = 0 ; Q < (1 << k) ; Q ++)
    {
        
        // int Q = 13; ////////////////////////////////////////////////////



        for(int i = 1 ; i <= n + k ; i ++) fa[i] = i;
        int cnt2 = 0;
        long long sum = 0;
        int QQ = Q , num = 1 , fuck = 0;
        // memcpy(tmp2 , tmp , sizeof(tmp));
        for(int i = 1 ; i <= cnt ; i ++) tmp2[i] = tmp[i];
        while(QQ)
        {
            if(QQ & 1)
            {
                sum += c[num];
                // printf("hello %d\n" , sum);
                for(int i = 1 ; i <= n ; i ++)
                {
                    ++ cnt2;
                    tmp2[cnt2 + cnt] = {num + n , i , a[num][i]};
                    // ++ cnt2;
                    // tmp2[cnt2 + cnt] = {i , num + n , a[num][i]};
                }
                fuck ++;
            }
            num ++ , QQ >>= 1;
        }
        sort(tmp2 + 1 , tmp2 + cnt2 + cnt + 1);
        int oknum = 1;
        for(int i = 1 ; i <= cnt2 + cnt ; i ++)
        {
            int u = tmp2[i].u , v = tmp2[i].v , w = tmp2[i].w;
            int uu = get_fa(u) , vv = get_fa(v);
            if(uu == vv) continue;
            fa[uu] = vv;
            oknum ++;
            sum += w * 1ll;
            // printf("u:%d v:%d w:%d sum:%d oknum:%d\n" , u , v , w , sum , oknum);
            if(oknum == n + fuck) break;
        }
        // printf("sum**********%d %d\n" , sum , Q);
        if(oknum == n + fuck) ans = min(ans , sum);
    }
    printf("%lld" , ans);
    return 0;
}