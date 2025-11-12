#include <bits/stdc++.h>
using namespace std;

long long da = 0;

void dfs(vector<int>& p, int L = 0, long long h = 0)
{
    for(int i = L, n = p.size();i < n;++i)
    {
        if(L >= 3 && p[i] * 2 >= h) break;
        dfs(p, i + 1, h + p[i]);
        if(i + 1 >= 3) {
			++da;
			da %= 998244353;
		}
    }
}

int main()
{
    int len;
    cin >> len;
    vector<int> p(len);
    for(int& i : p)
    {
        cin >> i;
    }
    sort(p.begin(), p.end());
    dfs(p);
    cout << da;
    return 0;
}
