# include <iostream>
# include <algorithm>
# include <cstdio>
# include <vector>
using namespace std;

struct score
{
    bool self;
    int point;
};

bool comp(struct score a, struct score b)
{
    return a.point > b.point;
}


int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n = 0, m = 0;
    cin >> n >> m;
    vector<struct score> a;
    for (int i = 0; i < n * m; i++)
    {
        struct score ai;
        if (i == 0)
        {
            ai.self = true;
        }
        else
        {
            ai.self = false;
        }
        cin >> ai.point;
        a.push_back(ai);
    }
    sort(a.begin(), a.end(), comp);
    int ni = 0, mi = 0;
    bool odd = true;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].self)
        {
            int num = i + 1;
            int nself = num % n;
            int mself = num / n + 1;
            if (nself == 0)
            {
                nself = n;
                mself--;
            }
            if (mself % 2 == 0)
            {
                nself = n - nself + 1;
            }
            cout << mself << " " << nself;
            break;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
