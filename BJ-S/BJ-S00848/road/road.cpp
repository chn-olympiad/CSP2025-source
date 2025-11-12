#define MAXK 15
#define MAXN 10010
#define MAXM 100010
typedef unsigned long long ull;
#include <queue>
#include <cstdio>
#include <cstring>
#include <tuple>
#include <set>
using namespace std;

priority_queue<pair<int, tuple<int, int, int>>> allRoad;
int totalSetNum;
int citySet[MAXN + MAXK];
bool visited[MAXN];
int n, m, k;
int c[MAXK];
int a[MAXK][MAXN];

void getInput()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; ++i)
    {
        int ui, vi;
        int wi;
        scanf("%d %d %d", &ui, &vi, &wi);
        allRoad.emplace(make_pair(-wi, make_tuple(ui, vi, -1)));
    }

    for (int j = 1; j <= k; ++j)
    {
        scanf("%d", &c[j]);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[j][i]);
    }
}

void initSet()
{
    for (int i = 1; i <= n; ++i)
        citySet[i] = i;

    totalSetNum = n;
}

int findSet(int i)
{
    if (citySet[i] == i) return i;

    int res = findSet(citySet[i]);
    citySet[i] = res;
    return res;
}

void mergeSet(int i, int j)
{
    if (findSet(i) == findSet(j)) return;
    citySet[findSet(j)] = findSet(i);
    --totalSetNum;
}

priority_queue<pair<int, tuple<int, int, int>>> selectedRoad;
priority_queue<pair<int, tuple<int, int, int>>> originSelectedRoad;
int biggestRoad = 0;
ull makeShort()
{
    ull res = 0;
    initSet();
    while (totalSetNum > 1 && !allRoad.empty()) // Shouldn't be possible to be empty
    {
        pair<int, tuple<int, int, int>> high = allRoad.top();
        allRoad.pop();
        int u, v, cityBelong;
        tie(u, v, cityBelong) = high.second;
        if (findSet(u) == findSet(v)) continue;
        selectedRoad.emplace(high);
        res += -high.first;
        mergeSet(u, v);
        if (totalSetNum == 1) biggestRoad = -high.first;
    }

    set<int> newCity;
    originSelectedRoad = selectedRoad;
    for (int j = 1; j <= k; ++j)
    {
        if (c[j] >= res) continue;
        allRoad = selectedRoad;
        selectedRoad = {};
        ull crrRes = 0;
        initSet();
        for (int ii = 1; ii <= n; ++ii)
            for (int jj = ii + 1; jj <= n; ++jj)
                if (a[j][ii] + a[j][jj] <= biggestRoad)
                    allRoad.emplace(make_pair(-a[j][ii] -a[j][jj], make_tuple(ii, jj, j)));
        set<int> newCityIn;
        while (totalSetNum > 1 && !allRoad.empty()) // Shouldn't be possible to be empty
        {
            pair<int, tuple<int, int, int>> high = allRoad.top();
            allRoad.pop();
            int u, v, cityBelong;
            tie(u, v, cityBelong) = high.second;
            if (findSet(u) == findSet(v)) continue;
            selectedRoad.emplace(high);
            crrRes += -high.first;
            mergeSet(u, v);
            newCityIn.emplace(cityBelong);
            if (totalSetNum == 1) biggestRoad = -high.first;
        }

        int totalCj=0;
        for (int i : newCityIn)
            totalCj+=c[i];

        if (crrRes + totalCj < res)
        {
            res = crrRes + totalCj;
            newCity = newCityIn;
            originSelectedRoad = selectedRoad;
        }
        else
        {
            selectedRoad = originSelectedRoad;
        }
    }

    return res;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    getInput();
    printf("%llu\n", makeShort());

    return 0;
}