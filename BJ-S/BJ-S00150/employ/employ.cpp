#include<bits/stdc++.h>
using namespace std;
int n,m,ans,cnt,cannum; // yingpinyuluyong
string s; // nandu
int can[550],canisnothere[550];
void dfs(int day)
{
    if(cannum<=0)
    {
        if(cnt>=m) ans++;
        return ;
    }
    for(int i = 1;i<=n;i++)
    {
        if(day > can[i])
        {
            canisnothere[i] = 1;
            cannum--;
            cout <<"a";
            continue;
        }
        if(s[day-1]=='1'&&canisnothere[i]==0)
        {
            canisnothere[i] = 1;
            cnt++;
            cannum--;
            cout <<"e";
            dfs(day+1);
            canisnothere[i] = 0;
            cnt--;
        }
        else
        {
            cout <<"c";
            dfs(day+1);
        }
    }
}
int main()
{
    freopen("employ1.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    ans = 0,cnt = 0,cannum = n;
    for(int i = 1;i<=n;i++)
    {
        cin >> can[i];
    }
    dfs(1);
    cout << ans;
    return 0;
}
