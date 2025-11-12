#include <bits/stdc++.h>

using namespace std;
const int maxn = 100005;
struct Node
{
    int i;
    int val;
};

int n;
int a[maxn][10];
int big[maxn][10];

bool cmp(Node aa, Node bb)
{
    if(aa.val == bb.val)
    {
        return aa.i < bb.i;
    }
    return aa.val > bb.val;
}





void biggg(int i)
{
    Node node[4];
    node[1].i = 1;
    node[1].val = a[i][1];
    node[2].i = 2;
    node[2].val = a[i][2];
    node[3].i = 3;
    node[3].val = a[i][3];

    sort(node+1, node+3+1, cmp);
    big[i][1] = node[1].i;
    big[i][2] = node[2].i;
    big[i][3] = node[3].i;
}
Node cnttt[4];
int t;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;



    while(t--)
    {
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(big, 0, sizeof(big));
        memset(cnttt,0,sizeof(cnttt));
        cnttt[1].i=1;
        cnttt[2].i=2;
        cnttt[3].i=3;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            biggg(i);
            cnttt[big[i][1]].val++;
        }
        sort(cnttt+1,cnttt+4,cmp);
        int ans = 0;
        //cout<<"Perfect!\n";
        for(int i = 1; i <= n; i++)
        {
            ans += a[i][big[i][1]];
        }
        if(cnttt[1].val > n/2)
        {
            int iii = cnttt[1].i;
            vector<int>cha;
            for(int i = 1; i <= n; i++)
            {
                if(big[i][1] == iii)
                {
                    cha.push_back(a[i][big[i][1]] - a[i][big[i][2]]);
                }
            }
            sort(cha.begin(), cha.end());
            int iter = 0;
            while(cnttt[1].val > n/2)
            {
                ans -= cha[iter];
                iter++;
                cnttt[1].val--;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
