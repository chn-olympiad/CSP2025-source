#include <bits/stdc++.h>
using namespace std;
int n, m; // hang/lie
const int MAXN = 15 * 15;
int scores[MAXN];
int seat[15][15];
int target;
int ansC, ansR;

bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    cin >> target;
    scores[1] = target;
    for (int i = 2; i <= n * m; i++)
    {
        //
        cin >> scores[i];
    }
    // sort the scores, bigger first

    sort(scores + 1, scores + n * m + 1, cmp); // 
    // shang dao xia: true
    // xia dao shang: false
    bool dir = true;
    bool flag = false;
    int currstu = 1;
    for (int i = 1; i <= m; i++) // LIE
    {
        if (dir)
        {
            for (int j = 1; j <= n; j++) // ZHU HANG
            {
                if (scores[currstu] == target)
                {
                    flag = true;
                    ansC = i, ansR = j;
                    break;
                }
                currstu++;
            }
        }
        else
        {
            for (int j = n; j >= 1; j--) // ZHU HANG
            {
                if (scores[currstu] == target)
                {
                    flag = true;
                    ansC = i, ansR = j;
                    break;
                }
                currstu++;
            }
        }
        if (flag)
        {
            break;
        }
        dir = !dir;
        //currstu++;
    }
    cout << ansC << ' ' << ansR << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}