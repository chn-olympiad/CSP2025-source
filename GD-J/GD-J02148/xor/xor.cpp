#include<bits/stdc++.h>
using namespace std;
using lint = long long;
const int N = 5e5 + 10;
lint st[N],xorPrefix[N],nxt[N],cnt[N];
vector<pair<int,int>> lr;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> st[i];
        xorPrefix[i] = st[i] ^ xorPrefix[i - 1];
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = i;j <= n;j++)
        {
            if((xorPrefix[j] ^ xorPrefix[i - 1]) == k)
            {
                lr.push_back({i,j});
                nxt[i] = j + 1;
                break;
            }
        }
        if(!nxt[i])
        {
            nxt[i] = n + 2;
        }
    }
    lint maxn = 0;
    cnt[n + 2] = -1;
    for(int i = n;i >= 1;i--)
    {
        cnt[i] = cnt[nxt[i]] + 1;
        for(int j = i;j < nxt[i];j++)
        {
            cnt[i] = max(cnt[i],cnt[j]);
        }
        maxn = max(maxn,cnt[i]);
    }
    cout << maxn;
	return 0;
}
