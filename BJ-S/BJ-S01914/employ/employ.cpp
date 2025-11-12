#include <bits/stdc++.h>
using namespace std;
int n,m,c[1000],id[1000];
char s[1000];
long long sum,num,ans;
long long N= 998244353;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> s[i];
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> c[i];
        id[i] = i;
    }
    do{
        sum = 0,num = 0;
        for(int i= 1;i <= n;i++)
        {
            if(s[i] == '0')
                num++;
            else{
                if(c[id[i]] <= num)
                    num++;
                else
                    sum++;
            }
        }
        if(sum >= m)
            ans++;
    }while(next_permutation(id+1,id + n + 1));
    cout << ans % N;
    return 0;
}