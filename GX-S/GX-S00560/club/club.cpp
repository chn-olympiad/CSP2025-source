#include<bits/stdc++.h>
using namespace std;
int t, n;
int maxx = -100000;
int ar[100000][3];
int d1, d2, d3;
int c1[100000], c2[100000], c3[100000];
void dfs(int level, int num)
{

    if(level == n)
    {
        if(num > maxx && d1 <= n / 2 && d2 <= n / 2 && d3 <= n / 2) maxx = num;
        return;
    }
    if(d1 > n / 2) return;
    if(d2 > n / 2) return;
    if(d3 > n / 2) return;
    ////////////////////////////////////////////////////
    c1[d1] = ar[level][0];
    d1++;
    dfs(level + 1, num + ar[level][0]);
    d1--;
    c1[d1] = 0;
    ////////////////////////////////////////////////////
    c2[d2] = ar[level][1];
    d2++;
    dfs(level + 1, num + ar[level][1]);
    d2--;
    c2[d2] = 0;
    ////////////////////////////////////////////////////
    c3[d3] = ar[level][2];
    d3++;
    dfs(level + 1, num + ar[level][2]);
    d3--;
    c3[d3] = 0;
    ////////////////////////////////////////////////////
    return;

}
int main()
{
    freopen("club.in" , "r", stdin );
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d %d", &ar[i][0], &ar[i][1], &ar[i][2]);
        }
        dfs(0,0);
        cout << maxx << endl;
        maxx = -100000;
    }
    return 0;
}
