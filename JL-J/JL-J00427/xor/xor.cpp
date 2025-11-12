#include<bits/stdc++.h>
using namespace std;
struct node
{
    int l , r;
    bool operator < (const node &qwq) const
    {
        if(r == qwq.r) return l < qwq.l;
        return r < qwq.r;
    }
}qwq[500010];
int n , k , a[500010] , xor_[500010] , cnt , ans;
vector<int> v[1 << 21];
int main()
{
    freopen("xor.in" , "r" , stdin);
    // freopen("date.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    scanf("%d%d" , &n , &k);
    for(int i = 1 ; i <= n ; i ++) scanf("%d" , &a[i]) , xor_[i] = xor_[i - 1] ^ a[i] , v[xor_[i]].push_back(i);
    for(int i = 1 ; i <= n ; i ++)
    {
        int x = xor_[i - 1] ^ k;
        auto id = lower_bound(v[x].begin() , v[x].end() , i);
        if(id == v[x].end()) continue;
        int y = *id; qwq[++ cnt] = {i , y};
    }
    sort(qwq + 1 , qwq + cnt + 1);
    int pos = 0;
    for(int i = 1 ; i <= cnt ; i ++)
    {
        if(qwq[i].l > pos) pos = qwq[i].r , ans ++;
    }
    printf("%d" , ans);
    return 0;
}