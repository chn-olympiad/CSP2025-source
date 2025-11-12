#include <bits/stdc++.h>

using namespace std;
const int N = 3e6 + 5;
int n , k , a[N] , sum[N];
int m , nowl , nowr , ans;
struct node
{
    int l , r;
}p[N];
bool cmp(node x , node y)
{
    if(x.r == y.r)
    {
        return x.l < y.l;
    }
    else
    {
        return x.r < y.r;
    }
}
int main()
{
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    scanf("%d %d" , & n , & k);
    for(int i = 1 ; i <= n ; ++ i)
    {
        scanf("%d" , & a[i]);
        sum[i] = sum[i - 1] ^ a[i];
        if(a[i] == k)
        {
            p[++ m].l = i , p[m].r = i;
        }
    }
    for(int i = 1 ; i <= n ; ++ i)
    {
        for(int j = i + 1 ; j <= n ; ++ j)
        {
            if((sum[j] ^ sum[i - 1]) == k)
            {
                p[++ m].l = i , p[m].r = j;
            }
        }
    }
    sort(p + 1 , p + 1 + m , cmp);
    for(int i = 1 ; i <= m ; ++ i)
    {
        if(nowr < p[i].l)
        {
            nowl = p[i].l;
            nowr = p[i].r;
            ans ++;
        }
    }
    printf("%d" , ans);
    return 0;
}
