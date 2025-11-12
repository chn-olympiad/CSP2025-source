#include <bits/stdc++.h>

using namespace std;

int num[100010][3];
int place[100010][3];
int cha[100010];

int t;
int n;
long long ans;

int cmp(int a, int b)
{
    return cha[a] < cha[b];
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin >> t;
    while(t--)
    {
        ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> num[i][0] >> num[i][1] >> num[i][2];
            if(num[i][0] >= num[i][1] && num[i][0] >= num[i][2])
            {
                place[i][0] = 0;
                if(num[i][1] >= num[i][2])
                {
                    place[i][1] = 1;
                    place[i][2] = 2;
                }
                else
                {
                    place[i][1] = 2;
                    place[i][2] = 1;
                }
            }
            else if(num[i][1] >= num[i][0] && num[i][1] >= num[i][2])
            {
                place[i][0] = 1;
                if(num[i][0] >= num[i][2])
                {
                    place[i][1] = 0;
                    place[i][2] = 2;
                }
                else
                {
                    place[i][1] = 2;
                    place[i][2] = 0;
                }
            }
            else
            {
                place[i][0] = 2;
                if(num[i][0] >= num[i][1])
                {
                    place[i][1] = 0;
                    place[i][2] = 1;
                }
                else
                {
                    place[i][1] = 1;
                    place[i][2] = 0;
                }
            }
            cha[i] = num[i][place[i][0]] - num[i][place[i][1]];
        }

        int a[100010], b[100010], c[100010];
        int cnta = 0, cntb = 0, cntc = 0;
        for(int i = 1; i <= n; i++)
        {
            if(place[i][0] == 0)
            {
                a[++cnta] = i;
            }
            else if(place[i][0] == 1)
            {
                b[++cntb] = i;
            }
            else c[++cntc] = i;
        }

        if(cnta > n / 2)
        {
            sort(a + 1, a + cnta + 1, cmp);
            for(int i = 1; i <= cnta - n / 2; i++)
            {
                int p = a[i];
                a[i] = 0;
                if(place[p][1] == 1) b[++cntb] = p;
                else c[++cntc] = p;
            }
        }
        else if(cntb > n / 2)
        {
            sort(b + 1, b + cntb + 1, cmp);
            for(int i = 1; i <= cntb - n / 2; i++)
            {
                int p = b[i];
                b[i] = 0;
                if(place[p][1] == 0) a[++cnta] = p;
                else c[++cntc] = p;
            }
        }
        else if(cntc > n / 2)
        {
            sort(c + 1, c + cntc + 1, cmp);
            for(int i = 1; i <= cntc - n / 2; i++)
            {
                int p = c[i];
                c[i] = 0;
                if(place[p][1] == 0) a[++cnta] = p;
                else b[++cntb] = p;
            }
        }
        num[0][0] = num[0][1] = num[0][2] = 0;
        for(int i = 1; i <= cnta; i++) ans += num[a[i]][0];
        for(int i = 1; i <= cntb; i++) ans += num[b[i]][1];
        for(int i = 1; i <= cntc; i++) ans += num[c[i]][2];

        cout << ans << "\n";
    }

    return 0;
}
