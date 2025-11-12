#include <bits/stdc++.h>
using namespace std;
const long long N=505,mod=998244353;
long long s[N],c[N],a[N];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    char ch;
    long long n,m,i,flag=0,ans=0;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> ch;
        s[i] = (int)(ch-'0');
        flag += (s[i]==1);
    }
    for (i = 1; i <= n; i++)
        cin >> c[i];
    for (i = 1; i <= n; i++)
        a[i] = i;
    do{
        int cnt=0,sum=0;
        for (i = 1; i <= n; i++)
        {
            if (c[a[i]]>cnt && s[i]==1)
                sum++;
            else
                cnt++;
        }
        if (sum >= m)
            ans = (ans+1)%mod;
    }while (next_permutation(a+1,a+1+n));
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}