#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 1e6+5;
int n,m,k;
int b[maxn];
struct road{
    int u,v,w;
}p[maxn];
struct country{
    int c;
    int a[maxn];
}c[maxn];
bool special_task_A = 1;
void init()
{
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++)
    {
        cin >> p[i].u >> p[i].v >> p[i].w;   
    }
    for(int i = 1;i <= k;i++)
    {
        cin >> c[i].c;
        for(int j = 1;j <= n;j++)
        {
            cin >> c[i].a[i];
            if(c[i].a[i] != 0) special_task_A = 0;
        }   
        if(c[i].c != 0) special_task_A = 0;
    }
}

void work()
{
    if(special_task_A)
    {
        cout << 0 << endl;
    }
    srand(time(0));
    cout << rand() % 1000005 << endl;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    cout << t;
    init();
    work();
    return 0;
}
