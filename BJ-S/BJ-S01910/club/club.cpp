#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5;
int t, n;
long long sum[4];
int len[4];
int over = 0;
vector<int> places[4];
struct Node{
    int x[4];
    int id1, id2, id3;
    int num;
    void read()
    {
        cin >> x[1] >> x[2] >>x[3];
        int maxn = max(x[1], max(x[2], x[3]));
        if(maxn == x[1])
        {
            id1 = 1;
            if(x[2] >= x[3])
            {
                id2 = 2;
                id3 = 3;
            }
            else
            {
                id2 = 3;
                id3 = 2;
            }
        }
        if(maxn == x[2])
        {
            id1 = 2;
            if(x[1] >= x[3])
            {
                id2 = 1;
                id3 = 3;
            }
            else
            {
                id2 = 3;
                id3 = 1;
            }
        }
        if(maxn == x[3])
        {
            id1 = 3;
            if(x[1] >= x[2])
            {
                id2 = 1;
                id3 = 2;
            }
            else
            {
                id2 = 2;
                id3 = 1;
            }
        }
        places[id1].push_back(num);
        sum[id1] += maxn;
    }
}a[NR];
bool cmp(int pos1, int pos2)
{
    return a[pos1].x[over] - a[pos1].x[a[pos1].id2] > a[pos2].x[over] - a[pos2].x[a[pos2].id2];
}
signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        sum[1] = sum[2] = sum[3] = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            a[i].num = i;
            a[i].read();
        }

        bool flag = 1;
        for(int i = 1; i <= 3; i++)
        {
            len[i] = places[i].size();
            if(len[i] > n / 2)
            {
                flag = 0;
                over = i;
                break;
            }
        }
        if(flag)
        {
            cout << sum[1] + sum[2] + sum[3] << "\n";
            for(int i = 1; i <= 3; i++)
            {
                places[i].clear();
            }
            continue;
        }
        //cout << over << "\n";
        sort(places[over].begin(), places[over].end(), cmp);
        for(int i = places[over].size() - 1; i >= n / 2; i--)
        {
            //cout << places[over][i] << " ";
            sum[over] -= a[places[over][i]].x[over];
            sum[a[places[over][i]].id2] += a[places[over][i]].x[a[places[over][i]].id2];
        }
        //cout << "\n";
        cout << sum[1] + sum[2] + sum[3] << "\n";
        for(int i = 1; i <= 3; i++)
        {
            places[i].clear();
        }
    }
    return 0;
}
