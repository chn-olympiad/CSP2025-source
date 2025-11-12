#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=100005;
int t, ret=0;
int n, cnt[4];
int satsfctn[N][4];

struct cr {
    int cr, s;  };
priority_queue<cr> person[N];
bool operator<(cr a, cr b)  {
    return a.s<b.s;  }

struct pl {
    int pl, s; };
priority_queue<pl> career[4];
bool operator<(pl a, pl b)  {
    return a.s>b.s;  }

void dfs(int i, int sums)
{
    if (i==n+1)  {
        ret=max(ret, sums);
        return;  }
    for (int j=1; j<=3; j++)
    {
        if (cnt[j]>=n/2)  continue;
        else  {
            cnt[j]++;
            dfs(i+1, sums+satsfctn[i][j]);
            cnt[j]--;  }
    }
}

void in(int i)  {
    int favcareer=person[i].top().cr;     // i's favourite career
    if (career[favcareer].size()>=n/2)  {    // if i's favourite career is full
        int leastperson=career[favcareer].top().pl;     // find out the person who contributed the least satisfaction
        cr p=person[leastperson].top();
        person[leastperson].pop();  // delete leastperson's first career
        int ns=person[i].top().s+person[leastperson].top().s;    // i's favourite career+leasrperson's second career
        if (ns>p.s)  {
            in(leastperson);   // Put leastperson into the second career.
            career[favcareer].pop();  // throw out the leastperson.
            career[favcareer].push({i, person[i].top().s});  // let i into his favourite career.
            return;  }
        else  {
            person[i].pop();  // delete i's favourite career
            in(i);  }  // place i
    }
    else  career[favcareer].push({i, person[i].top().s});
}

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%lld", &t);
    while (t--)
    {
        cnt[1]=cnt[2]=cnt[3]=ret=0;
        priority_queue<cr> person1[N];
        priority_queue<pl> career1[4];
        swap(person, person1);
        swap(career, career1);

        scanf("%lld", &n);
        if (n<=10)  {
            for (int i=1; i<=n; i++)
                for (int j=1; j<=3; j++)
                    scanf("%lld", &satsfctn[i][j]);
            dfs(1, 0);
            printf("%lld\n", ret);
        }
        else  {
            for (int i=1; i<=n; i++)
                for (int j=1; j<=3; j++)  {
                    int x;
                    scanf("%lld", &x);
                    person[i].push({j,x});  }
            for (int i=1; i<=n; i++)  in(i);
            for (int i=1; i<=3; i++)
                while (career[i].size())  {
                    ret+=career[i].top().s;
                    career[i].pop();  }
            printf("%lld\n", ret);
        }
    }
    return 0;
}
