#include<bits/stdc++.h>
using namespace std;
struct score
{
    int r1,r2,r3;
};score a[100005];

int n;

bool cmp(score x, score y)
{
    return x.r1 > y.r1;
}

int dfs(int i, int k)
{
    int maxans = -1;
    int ans = 0;
    int num1, num2, num3;
    if(i < n)
    {
        if(k == 1)ans += a[i].r1;
        if(k == 2)ans += a[i].r2;
        else ans += a[i].r3;
        if(num1 < (n/2) && num2 < (n/2))
        {
            if(a[i+1].r1 > a[i+1].r2) dfs(i+1, 1);
            else dfs(i+1,2);
        }
        else if(num1 == (n/2) && num2 < (n/2))
            return dfs(i+1,2);
        else if(num1 < (n/2) && num2 == (n/2))
            return dfs(i+1,1);
    }
    else
    {
        if(ans > maxans) maxans = ans;
    }
    return maxans;

}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    int sum = 0;
    for(int w = 0; w < t; w++)
    {
        sum = 0;

        cin >> n;
        for(int i = 0;i < n; i++)
        {
            cin >> a[i].r1 >> a[i].r2 >> a[i].r3;
        }
        bool A = 1;
        for(int i = 0; i < n; i ++)
        {
            if(a[i].r2 != 0 || a[i].r3 != 0)A = 0;
        }
        if(A)
        {
            sort(a, a + n, cmp);
            for(int i = 0;i < n /2; i++)
            {
                sum += a[i].r1;
            }
            cout << sum << endl;
        }
        bool B = 1;
        for(int i = 0; i < n; i ++)
        {
            if(a[i].r3 != 0)B = 0;
        }
        if(B)
        {
            sum = max(dfs(0,1), max(dfs(0,2), dfs(0,3)));
            cout << sum << endl;
        }
        if(n == 2)
        {
            int he[10];
            he[1] = a[0].r1 + a[1].r2;
            he[2] = a[0].r1 + a[1].r3;
            he[3] = a[0].r2 + a[1].r1;
            he[4] = a[0].r2 + a[1].r3;
            he[5] = a[0].r3 + a[1].r1;
            he[6] = a[0].r3 + a[1].r2;
            int maxhe = -1;
            for(int i = 1; i <= 6; i ++)
            {
                if(he[i] > maxhe) maxhe = he[i];
            }
            cout << maxhe << endl;
        }
        else{
            int num1, num2, num3;
            for(int i = 0; i < n; i ++)
            {
                int maxn = max(a[i].r1, max(a[i].r2, a[i].r3));
                if(maxn == a[i].r1)
                {
                    if(num1 < n / 2) sum += maxn;
                    else
                    {
                        if(a[i].r2 >= a[i].r3 && num2 < n / 2)
                        {
                            sum += a[i].r2;
                        }
                        else sum += a[i].r3;
                    }
                }
                else if(maxn == a[i].r2)
                {
                    if(num2 < n / 2) sum += maxn;
                    else
                    {
                        if(a[i].r1 >= a[i].r3 && num1 < n / 2)
                        {
                            sum += a[i].r1;
                        }
                        else sum += a[i].r3;
                    }
                }
                else
                {
                    if(num3 < n / 2) sum += maxn;
                    else
                    {
                        if(a[i].r1 >= a[i].r2 && num1 < n / 2)
                        {
                            sum += a[i].r1;
                        }
                    else sum += a[i].r2;
                    }
                }
            }
            cout << sum << endl;
        }
    }
    return 0;
}
