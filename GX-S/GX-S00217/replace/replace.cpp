#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200010;
int n,q;
string s1[MAXN],s2[MAXN];
string t1,t2;
string v1,v2;
int nxt1[MAXN],nxt2[MAXN];

bool pd(int x,int y)
{
    for (int i=0;i<s1[x].length();i++)
    {
        if (s1[x][i] != t1[y+i]) return 0;
        if (s2[x][i] != t2[y+i]) return 0;
    }
    return 1;
}

int getans()
{
    int res = 0;
    int key = 0;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<t1.length();j++)
        {
            if (pd(i,j)) key ++;
        }
        if (key == 1) res ++;
    }
    return res;
}

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    cin >> n >> q;
    for (int i=1;i<=n;i++)
    {
        cin >> s1[i] >> s2[i];
    }
    for (int i=1;i<=q;i++)
    {
        cin >> t1 >> t2;
        cout << getans() << endl;;
    }

    return 0;
}
