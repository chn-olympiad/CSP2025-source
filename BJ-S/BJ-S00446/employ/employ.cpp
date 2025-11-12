#include<bits/stdc++.h>
using namespace std;
int c[510], ans, d[510], n, m;
bool x[510];
string s;
void dfs(int st)
{
    if(st > n)
    {
        int shi = 0, cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(s[i] == '0' || shi >= c[d[i]])
            {
                shi++;
                continue;
            }
            cnt++;
        }
        if(cnt >= m)
        {
            ans++;
        }
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(x[i])
        {
            continue;
        }
        d[st] = i;
        x[i] = 1;
        dfs(st + 1);
        x[i] = 0;
    }
    return ;
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    
    cin >> n >> m;
    cin >> s;
    s = '$' + s;
    
    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    int shu1 = 0;
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == '0')
        {
            shu1++;
        }
    }
    if(n - shu1 < m)
    {
        cout << 0;
        return 0;
    }
    dfs(1);
    cout << ans;
    return 0;
}