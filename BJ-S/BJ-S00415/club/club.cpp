#include<bits/stdc++.h>
using namespace std;
int T;
int a[4][100005];
priority_queue<int, vector<int>, greater<int> > pq[4];
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        while(!pq[1].empty()) pq[1].pop();
        while(!pq[2].empty()) pq[2].pop();
        while(!pq[3].empty()) pq[3].pop();
        int n, cnt[4] = {0}, ans = 0;
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[1][i] >> a[2][i] >> a[3][i];
            if(a[1][i]>=a[2][i]&&a[1][i]>=a[3][i])
            {
                ans+=a[1][i];
                if(a[2][i]>=a[3][i]) pq[1].push(a[1][i]-a[2][i]);
                else pq[1].push(a[1][i]-a[3][i]);
                cnt[1]++;
            }
            else if(a[2][i]>=a[1][i]&&a[2][i]>=a[3][i])
            {
                ans+=a[2][i];
                if(a[1][i]>=a[3][i]) pq[2].push(a[2][i]-a[1][i]);
                else pq[2].push(a[2][i]-a[3][i]);
                cnt[2]++;
            }
            else if(a[3][i]>=a[1][i]&&a[3][i]>=a[2][i])
            {
                ans+=a[3][i];
                if(a[1][i]>=a[2][i]) pq[3].push(a[3][i]-a[1][i]);
                else pq[3].push(a[3][i]-a[2][i]);
                cnt[3]++;
            }
        }
        int pos = -1;
        if(cnt[1]>n/2) pos = 1;
        if(cnt[2]>n/2) pos = 2;
        if(cnt[3]>n/2) pos = 3;
        if(pos==-1)
        {
            cout << ans << "\n";
            continue;
        }
        while(cnt[pos]>n/2)
        {
            int t = pq[pos].top();
            pq[pos].pop();
            ans-=t;
            cnt[pos]--;
        }
        cout << ans << "\n";
    }
    return 0;
}
