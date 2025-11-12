#include <bits/stdc++.h>

using namespace std;

const int M = 998244353;
int n, m;
char s[510];
int pat[510];
int peo[510];

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    scanf("%d%d", &n, &m);
    scanf("%s", s+1);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &pat[i]);
        peo[i] = i;
    }
    sort(pat+1, pat+n+1);
    long long ans = 0;
    do
    {
        int dcnt = 0;
        for(int i=1;i<=n;i++)
        {
            if(dcnt >= pat[peo[i]]) dcnt++;
            else if(s[i] == '0') dcnt++;
        }
        if(n-dcnt >= m)
        {
            ans++;
            ans %= M;
        }
    }while(next_permutation(peo+1, peo+n+1));
    printf("%lld\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
