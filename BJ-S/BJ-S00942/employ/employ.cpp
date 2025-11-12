#include<bits/stdc++.h>
using namespace std;
const int M = 998244353;
string s;
int n,m;
int c[505];
/*
void dfs(int p)
{
    if(p > n)
    {

        return;
    }

}*/

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int cnt = 0;
    cin >> n >> m;
    cin >> s;
    for(int i = 1;i <= n;i++)
    {
        cin >> c[i];
        if(c[i] == 0) cnt++;
    }
    if(n-cnt < m)
    {
        cout << 0;
        return 0;
    }
    bool f = 1;
    for(int i = 0;i < n;i++) if(s[i] == '0') f = 0;
    if(f)
    {
        long long nul = 1;
        for(int i = 1;i <= n;i++) nul = nul*i%M;
        cout << nul << endl;
    }
    return 0;
}
