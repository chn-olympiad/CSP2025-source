#include <bits/stdc++.h>
#define loop(i, x, n) for(int i = x; i <= n; i++)
#define int long long
using namespace std;
int a[100005][4];
bool sel[100005][4];
int maxj(int A, int B, int C, int I)
{
    if (A >= max(B, C)) {sel[I][1] = 1; return 1;}
    if (B >= max(A, C)) {sel[I][2] = 1; return 2;}
    if (C >= max(A, B)) {sel[I][3] = 1; return 3;}
}
//bool cmp(vector<int> A, vector<int> B) {return (A <= B ? true : false);}
signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        memset(sel, 0, sizeof(sel));
        //loop (i, 1, sizeof(vis)) vis = 0;
        int n; cin >> n;
        int w[4] = {0}, wm = n / 2;
        loop (i, 1, n) loop (j, 1, 3) cin >> a[i][j];
        int dp = 0;
        loop(i, 1, n)
        {
            int j = maxj(a[i][1], a[i][2], a[i][3], i);
            dp += a[i][j];
            w[j]++;
        }
        // only 1 column's weight can be greater than wm
        int col = (w[1] > wm ? 1 : (w[2] > wm ? 2 : 3));
        if (col == 3 && w[3] <= wm)
        {
            cout << dp << endl;
            continue;
        }
        if (col == 1)
        {
            vector<int> dv;
            loop (i, 1, n)
            {
                if (sel[i][1]) dv.push_back(min(a[i][1] - a[i][2], a[i][1] - a[i][3]));
                //ddv.push_back({i, max(dv2.second, dv3.second) - min(dv2.second, dv3.second)});
                //sort(dv3.begin(), dv3.end(), cmp);
                //sort(ddv.begin(), ddv.end(), cmp);
            }
            sort(dv.begin(), dv.end());
            //int dv2p = 1, dv3p = 1, ddvp = 1;
            //ddvp = 1;
            loop (i, 0, dv.size() - 1)
            {
                /*if (dv2[i] <= dv3[i])
                {
                    //if (w[2] < wm) //
                    //{
                        dp -= dv2[i];
                        w[2]++; w[1]--;
                    /*}
                    else
                    {
                        if (dv3[i] <= ddv[ddvp] + dv2[i])
                        {
                            dp -= dv[3];
                            w[3]++; w[1]--;
                        }
                        else
                        {
                            dp -= (ddv[ddvp] + dv2[i]);
                            ddvp++;
                            w[3]++; w[1]--;
                        }
                    }
                }
                else
                {
                    //if (w[3] < wm)
                    //{
                        dp -= dv3[i];
                        w[3]++; w[1]--;
                    //}
                    /*else
                    {
                        if (dv2[i] <= ddv[ddvp] + dv3[i])
                        {
                            dp -= dv[3];
                            w[2]++; w[1]--;
                        }
                        else
                        {
                            dp -= (ddv[ddvp] + dv3[i]);
                            ddvp++;
                            w[2]++; w[1]--;
                        }
                    }
                }
            }
                if (w[1] == wm)
                {
                    cout << dp << endl;
                    break;
                }
            }*/
                dp -= dv[i];
                w[1]--;
                if (w[1] <= wm)
                {
                    cout << dp << endl;
                    break;
                }
    }
}

        if (col == 2)
        {
            vector<int> dv;
            loop (i, 1, n)
            {
                if (sel[i][2]) dv.push_back(min(a[i][2] - a[i][1], a[i][2] - a[i][3]));
            }
            sort(dv.begin(), dv.end());
            loop (i, 0, dv.size() - 1)
            {
                dp -= dv[i];
                w[2]--;
                if (w[2] == wm)
                {
                    cout << dp << endl;
                    break;
                }
            }
            }
        if (col == 3)
        {
            vector<int> dv;
            loop (i, 1, n)
            {
                if (sel[i][3]) dv.push_back(min(a[i][3] - a[i][1], a[i][3] - a[i][2]));
            }
            sort(dv.begin(), dv.end());
            loop (i, 0, dv.size() - 1)
            {
                dp -= dv[i];
                w[3]--;
                if (w[3] == wm)
                {
                    cout << dp << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
