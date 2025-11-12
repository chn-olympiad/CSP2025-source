#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 50;
int a[N][4];
int n;
int t;
int change[N]; //每一个人次选与最优选的差距
int ans;
int cnt[4];
priority_queue<int,vector<int>,greater<int>> p1,p2,p3;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin >> t;
    while(t--)
    {
        //cout << t << '\n';
        //cout << '\n';
        while(!p1.empty())
        {
            p1.pop();
        }
        while(!p2.empty())
        {
            p2.pop();
        }
        while(!p3.empty())
        {
            p3.pop();
        }
        ans = 0;
        for(int i = 1;i <= 3;i++) cnt[i] = 0;
        memset(a,0,sizeof(a));
        memset(change,0,sizeof(change));
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            int best;
            if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
            {
                best = a[i][1];
                cnt[1]++;
                if(a[i][2] >= a[i][3])
                {
                    change[i] = a[i][1] - a[i][2];
                    p1.push(change[i]);
                }
                else
                {
                    change[i] = a[i][1] - a[i][3];
                    p1.push(change[i]);
                }

            }
            else
            {
                if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3])
                {
                    best = a[i][2];
                    cnt[2]++;
                    if(a[i][1] >= a[i][3])
                    {
                        change[i] = a[i][2] - a[i][1];
                        p2.push(change[i]);
                    }
                    else
                    {
                        change[i] = a[i][2] - a[i][3];
                        p2.push(change[i]);
                    }

                }
                else
                {
                    if(a[i][3] >= a[i][1] && a[i][3] >= a[i][2])
                    {
                        best = a[i][3];
                        cnt[3]++;
                        if(a[i][1] >= a[i][2])
                        {
                            change[i] = a[i][3] - a[i][1];
                            p3.push(change[i]);
                        }
                        else
                        {
                            change[i] = a[i][3] - a[i][2];
                            p3.push(change[i]);
                        }

                    }

                }
            }
            ans += best;
        }
        if(cnt[1] > n / 2)
        {
            int num = cnt[1] - n / 2;
            while(num != 0 && !p1.empty())
            {
                int val = p1.top();
                p1.pop();
                num--;
                ans -= val;
               // cout << ans << ' ';
            }
        }
        if(cnt[2] > n / 2)
        {
            int num = cnt[2] - n / 2;
            while(num != 0 && !p2.empty())
            {
                int val = p2.top();
                p2.pop();
                num--;
                ans -= val;
                //cout << ans << ' ';
            }
        }
        if(cnt[3] > n / 2)
        {
            int num = cnt[3] - n / 2;
            while(num != 0 && !p3.empty())
            {
                int val = p3.top();
                p3.pop();
                num--;
                ans -= val;
                //cout << ans << ' ';
            }
        }
        cout << ans << '\n';
    }
	fclose(stdin);
	fclose(stdout);

    return 0;
}
