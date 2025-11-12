#include <fstream>
using namespace std;
ifstream cin("club.in");
ofstream cout("club.out");
int n;
int a[100001][4];
int cnt[4];
int ans;
void dfs(int step, int sum)
{
    if (step > n)
    {
        ans = max(ans, sum);
        return;
    }
    if (cnt[1] < n/2)
    {
        cnt[1]++;
        dfs(step+1, sum+a[step][1]);
        cnt[1]--;
    }
    if (cnt[2] < n/2)
    {
        cnt[2]++;
        dfs(step+1, sum+a[step][2]);
        cnt[2]--;
    }
    if (cnt[3] < n/2)
    {
        cnt[3]++;
        dfs(step+1, sum+a[step][3]);
        cnt[3]--;
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        ans = 0;
        dfs(1, 0);
        cout << ans << endl;
    }
    return 0;
}