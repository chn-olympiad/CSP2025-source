#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e5 + 5;
ll n,q,ans = 0;
string t1,t2;
string s[N][3];

void dfs(string t)
{
    if (t == t2){
        ans++;
    }
    string ss;
    for (size_t i = 0;i < t.size();i++){
        for (int j = 0;j < n;j++){
            ss = t;
            ss.erase(i + s[i][1].size() - 1);
            ss.erase(0,i - 1);
            if (ss == s[i][1])
            ss = t;
            for (size_t l = i;l < i + s[i][2].size() - 1;l++){
                ss[l] = s[i][2][l];
            }
            dfs(ss);
        }
    }
}

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for (int i = 1;i <= n;i++){
        cin >> s[i][1] >> s[i][2];
    }
    for (int i = 1;i <= q;i++){
        cin >> t1 >> t2;
        dfs(t1);
        cout << ans;
        ans = 0;
    }
    return 0;
}
