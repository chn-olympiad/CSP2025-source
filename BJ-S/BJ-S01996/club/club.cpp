//感觉像反悔贪心
//对于每个人，先把他优先放到价值最大的部门，然后往优先队列里推入转到另外两个部门所要减少的总满意度
//如果人数超了就挑选一个转走代价最小的卷铺盖走人
#include <iostream>
#include <queue>

using namespace std;

typedef long long LL;

const int N = 1e5+5;

int T;

int n;
int lim;
LL a[N][5];    //the satisfaction of each person
LL ans = 0;
LL cnt[3];  //每个部门的当前人数
int bl[N];  //每个人的归属

int decide(int u)   //选出一个价值最大的部门
{
    int now = 1;
    if(a[u][2] > a[u][now]) now = 2;
    if(a[u][3] > a[u][now]) now = 3;
    return now;
}

struct mem //每个成员 member
{
    int id; //编号
    int v;  //要转去的公司
    LL val; //存放转走后增加的收益（可能为负）
    //重载运算符，只通过价值进行比较
    bool operator < (const mem &x) const
    {
        return val < x.val;
    }
    bool operator > (const mem &x) const
    {
        return val > x.val;
    }
};

priority_queue<mem, vector<mem>, less<mem> > q[4]; //大根堆，存放每个人转走后增加的收益（可能为负）

int main()
{
    //freopen("club5.in","r",stdin);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while(T--)
    {
        //初始化
        cnt[1] = cnt[2] = cnt[3] = 0;
        ans = 0;
        scanf("%d",&n);
        lim = n>>1;
        //cout << lim << endl;
        for(int i = 1;i <= n;i++)   //input
        {
            for(int j = 1;j <= 3;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(int i = 1;i <= n;i++)
        {
            int to = decide(i);
            ans += a[i][to];
            bl[i] = to;
            //printf("bl[%d]=%d=%d\n", i, to, bl[i]);
            //printf("%d->%d\n", i, bl[i]);
            cnt[to]++;
            if(to != 1) q[to].push({i, 1, a[i][1]-a[i][to]});
            if(to != 2) q[to].push({i, 2, a[i][2]-a[i][to]});
            if(to != 3) q[to].push({i, 3, a[i][3]-a[i][to]});
        }
        while(cnt[1] > lim || cnt[2] > lim || cnt[3] > lim )
        {
            for(int i = 1;i <= 3;i++)
            {
                //printf("q[%d].size=%lld\n", i, q[i].size());
                //printf("cnt[%d]=%d\n", i, cnt[i]);
                if(cnt[i] > lim)
                {
                    while(!q[i].empty() && bl[q[i].top().id] != i)
                    {
                        //puts("2131231231");
                        //printf("%d %d %d\n", q[i].top().id, q[i].top().v, q[i].top().val);
                        //printf("bl[%d]=%d\n", q[i].top().id, bl[q[i].top().id]);
                        q[i].pop();
                    }
                //printf("nownownow q[%d].size=%d\n", i, q[i].size());
                    if(q[i].empty()) return 0;
                    //转走
                    mem tp = q[i].top();
                    q[i].pop();
                    int u = tp.id;  //当前成员
                    int v = tp.v;   //目标社团
                    int val = tp.val;
                    bl[u] = v;
                    ans += val;
                    cnt[i]--;
                    cnt[v]++;
                    if(v != 1) q[v].push({u, 1, a[u][1]-a[u][v]});
                    if(v != 2) q[v].push({u, 2, a[u][2]-a[u][v]});
                    if(v != 3) q[v].push({u, 3, a[u][3]-a[u][v]});
                }
            }
        }
        printf("%lld\n", ans);

        //重置
        while(!q[1].empty()) q[1].pop();
        while(!q[2].empty()) q[2].pop();
        while(!q[3].empty()) q[3].pop();
        for(int i = 1;i <= n;i++) bl[i] = 0;
    }
    return 0;
}
