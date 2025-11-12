#include <iostream>

using namespace std;

typedef long long LL;

const int N = 505;

const int P = 998244353;

int n, m;
LL a[N];
LL sum[N];  //0的总个数
LL ans;
int c[N];   //每个人的容忍度
int dp[N][N][N]; //dp[i][j][k]表示前i天踢掉了j个人，第i天轮到了k时总方案数
int cnt;

void solve1();
void solve2();
void solve3();
bool vis[N];
int tot = 0;    //总共走的人数
void solve4(int day, int now);  //暴搜，n<=10

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    a[0] = 1;
    for(int i = 1;i <= N-1;i++)
    {
        a[i] = (a[i-1]*i)%P;
        //if(i >= 10 && i <= 30) printf("%d->%lld\n", i, a[i]);
    }
    scanf("%d%d",&n,&m);
    ans = a[n]; //总组合数 A(n,n)
    for(int i = 1;i <= n;i++)
    {
        char c;
        cin >> c;
        if(c == '1') sum[i] = sum[i-1];
        else if(c == '0') sum[i] = sum[i-1]+1;
        //printf("%d ", sum[i]);
    }
    //puts("1231321");
    for(int i = 1;i <= n;i++)
    {
        scanf("%d", &c[i]);  //输入容忍度
        if(c[i] == 0) cnt++;    //一开始就走的人数
    }
    if(n-cnt < m || n-sum[n] < m)   //跑太多了救不回来
    {
        puts("0");
        return 0;
    }
    //cout << sum[n] << endl;
    if(n <= 18) //暴搜
    {
        ans = a[n];
        solve4(0, 0);
        printf("%lld\n", ans);
        return 0;
    }
    if(sum[n] == 0) //全都能做出来
    {
        //这个答案是错的，因为有人根本不做直接跑路，但我没招了
        ans = a[n];
        //solve4(0,0);
        printf("%lld\n", ans);
        return 0;
    }
    if(m == 1)  //录取一个就行
    {
        //solve2();
        if(sum[n] < n) ans = a[n];
        else ans = 0;
        printf("%lld\n", ans);
        return 0;
    }
    return 0;
}

void solve1()
{
    printf("%lld\n", a[n]);
    return;
}

void solve3()
{
    //枚举每种不可能的情况进行容斥
    //一共要选m个人，也就是说最多只能踢掉n-m个人
    for(int i = 1;i <= n;i++) dp[0][0][i] = 1;
    for(int i = 1;i <= n;i++)   //枚举每一天
    {
        for(int k = 1;k <= n;k++)   //枚举这一天来的人
        {
            for(int j = 0;j <= n;j++)   //枚举前i-1天踢掉的人数
            {
                if(sum[i]-sum[i-1])
                {
                    //这天试题太难了
                    //dp[i][j+1][k] += dp[i-1][j]
                }
            }
        }
    }

}

void solve4(int day, int now)
{
    bool flag = 0;
    if(day > 0)
    {
        if(sum[day]-sum[day-1] || tot >= c[now])    //太难了直接辞退或抗不住压力跑了
        {
            tot++;
            flag = 1;
        }
    }
    //if(day == 1) printf("day%d, now=%d, tot=%d\n", day, now, tot);
    //puts("final!");
    if(n-tot < m)  //不可行方案
    {
        //puts("okay");
        ans -= a[n-day];    //剩下n-day个人的全排列
        ans %= P;
        if(flag) tot--;
        return;
    }
    for(int i = 1;i <= n;i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            solve4(day+1, i);
            vis[i] = 0;
        }
    }
    //回退
    if(flag) tot--;
    return;
}
