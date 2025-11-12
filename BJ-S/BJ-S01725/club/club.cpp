#include<bits/stdc++.h>
using namespace std;

struct node
{
    int id;
    int one, two, three;
    int ch;
}a[100005];



node q1[100005];
node q2[100005];
node q3[100005];

bool cmp (node x, node y)
{
    return x.ch < y.ch;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        for (int i = 1; i <= 100001; i++)
        {
            node ze;
            ze.id = 0, ze.one = 0, ze.ch = 0, ze.two = 0, ze.three = 0;
            q1[i] = ze;
            q2[i] = ze;
            q3[i] = ze;
            a[i] = ze;
        }
        int cnt1 = 1, cnt2 = 1, cnt3 = 1;
        int n;
        cin >> n;
        long long sum = 0;
        for(int i = 1; i <= n; i++)
        {
            a[i].id = i;
            cin >> a[i].one >> a[i].two >> a[i].three;
            if (a[i].one >= a[i].two && a[i].one >= a[i].three)
            {
                 a[i].ch = min (a[i].one - a[i].two, a[i].one - a[i].three);
                 q1[cnt1] = a[i];
                 sum += a[i].one;
                 cnt1++;
            }
            else if (a[i].one <= a[i].two && a[i].two >= a[i].three)
            {
                a[i].ch = min (a[i].two - a[i].one, a[i].two - a[i].three);
                 q2[cnt2] = a[i];
                 sum += a[i].two;
                 cnt2++;
            }
            else
            {
                a[i].ch = min (a[i].three - a[i].two, a[i].three - a[i].one);
                 q3[cnt3] = a[i];
                 sum += a[i].three;
                 cnt3++;
            }
        }
        cnt1--;
        cnt2--;
        cnt3--;
        if (cnt1 > n / 2)
        {
            sort(q1 + 1, q1 + cnt1 + 1, cmp);
            for (int i = 1; i <= cnt1 - n / 2; i++)
            {
                sum -= q1[i].ch;
            }

        }
        else if (cnt2 > n / 2)
        {
            sort(q2 + 1, q2 + cnt2 + 1, cmp);
            for (int i = 1; i <= cnt2 - n / 2; i++)
            {
                sum -= q2[i].ch;
            }
        }
        else if (cnt3 > n / 2)
        {
            sort(q3 + 1, q3 + cnt3 + 1, cmp);
            for (int i = 1; i <= cnt3 - n / 2; i++)
            {
                sum -= q3[i].ch;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
