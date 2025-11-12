#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int minn = 100000;
int rod[10000];
struct road
{
    int from1, from2;
    int money;
}rd[10000];
bool cheak()
{
    for(int i = 0; i < n; i++)
    {
        if(rod[i] == 0)
        {
            return false;
        }
    }
    return true;
}
void dfs(int level, int mny)
{
    if(level == m)
    {
        if(cheak())
        {
            minn = mny < minn ? mny : minn;
        }
        return;
    }
    rod[rd[level].from1] = 1;
    rod[rd[level].from2] = 1;
    dfs(level + 1, mny + rd[level].money);
    rod[rd[level].from1] = 0;
    rod[rd[level].from2] = 0;
    dfs(level + 1, mny);

}
int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        cin >> rd[i].from1 >> rd[i].from2 >> rd[i].money;
        rd[i].from1--;
        rd[i].from2--;
    }
    dfs(0,0);
    cout << minn;
    return 0;
}
