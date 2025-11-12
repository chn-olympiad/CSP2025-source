#include <bits/stdc++.h>
// #include <dragonpro.h>
#define ll long long
// #define pr pair<,>
using namespace std;
const int MOD = 998244353;
int n;
struct node
{
    int len , id;
    bool vis;
}a[5010];
bool cmp(node x , node y)
{
    return x.len < y.len;
}
bool is_polygon(stack<node> stck)
{
    int f = stck.top().len, sum = 0;
    while(!stck.empty())
    {
        sum += stck.top().len;
        stck.pop();
    }
    if(f * 2 < sum) return true;
    else return false;
}
int dfs(int k , stack<node> stk)
{
    if(k == 0)
    {
        if(is_polygon(stk)) return 1;
        else return 0;
    }
    int res = 0 , topk;
    if(stk.empty()) topk = 1;
    else topk = stk.top().id;
    for(int i = topk ; i <= n ; i ++)
        if(a[i].vis == false)
        {
            stk.push(a[i]); a[i].vis = true;
            res += dfs(k - 1 , stk);
            stk.pop(); a[i].vis = false;
        }
    return res;
}
void part_scores_1()
{
    ll ans = 0 , ansk = n * (n - 1) / 2 ;
    int mul = n - 2, div = 3;
    for(int i = 3 ; i <= n ; i ++)
    {
        ansk = ansk * mul / div;
        ans += ansk % MOD; mul -- , div ++;
    }
    cout << ans % MOD << endl;
    exit(0);
}
void part_scores_2()
{
    int cnt = 0;
    if(a[3].len < a[1].len + a[2].len) cnt ++;
    cout << cnt << endl;
    exit(0);
}
void part_scores_3()
{
    ll ans = 0;
    for(int w = 3 ; w <= n ; w ++)
    {
        stack<node> st;
        ans += dfs(w , st) % MOD;
    }
    cout << ans % MOD << endl;
    exit(0);
}
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin >> n;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i].len;
    sort(a + 1 , a + n + 1 , cmp);
    for(int i = 1 ; i <= n ; i ++)
        a[i].id = i , a[i].vis = false;
    if(a[n].len == 1) part_scores_1();
    if(n == 3) part_scores_2();
    if(n <= 20) part_scores_3();
    cout << "Sorry , but I can't do this ..." << endl;
	return 0;
}
// dragonpro-presents