//CSP-J T1 number
#include <bits/stdc++.h>

#define MAX_N 10
#define MOD 998244353

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

string s;
int cnt[MAX_N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    int i, j;

    cin>>s;

    for(i=0;i<s.size();++i)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            cnt[s[i]-'0'] ++;
        }
    }

    for(i=9;i>=0;--i)
        for(j=1;j<=cnt[i];++j)
            cout<<i;

    cout<<'\n';

    return 0;
}

/*
5
1 1 1 1 1
0
*/