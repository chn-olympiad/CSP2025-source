#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[5050],ans = 0;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin >> n;
    int maxa = -1;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(a[i] >= maxa)
            maxa = a[i];
    }
    if(n == 3)
    {
        int sum0 = a[1] + a[2] + a[3];
        if(sum0 > 2 * maxa)
            cout << 1;
        else cout << 0;
        return 0;
    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[5050],ans = 0,p[5005][705];
ll zhi[705],k = 1;
const int MOD = 998244353;
bool prime(int a)
{
    if(a == 2)
        return true;
    for(int i = 2;i <= sqrt(a);i++)
    {
        if(a % i == 0)
            return false;
    }
    return true;
}
ll C(int up,int down)
{
    int sum = 1;
    ll ls[705];//ling shi
    ll lsup[705];
    ll lsdown[705];
    for(int i = 1;i <= up;i++)
    {
        for(int j = 1;j <= 700;j++)
        {
            lsdown[j] += p[i][j];
        }
    }
    for(int i = down;i >= down - up + 1;i--)
    {
        for(int j = 1;j <= 700;j++)
        {
            lsup[j] += p[i][j];
        }
    }
    for(int i = 1;i <= 700;i++)
    {
        ls[i] = lsup[i] - lsdown[i];
    }
    for(int i = 1;i <= 700;i++)
    {
        for(int j = 1;j <= ls[i];j++)
        {
            sum = sum * abs(zhi[j]) % MOD;
        }
    }
    return sum;
}
int main()
{
//    freopen("polygon.in","r",stdin);
//    freopen("polygon.out","w",stdout);
    memset(zhi,-1,sizeof(zhi));
    for(int i = 2;i <= 5000;i++)
    {
        if(prime(i))
        {
            zhi[k] = i;
            k++;
        }
    }
    for(int i = 2;i <= 5000;i++)
    {
        ll pk = i;
        for(int j = 1;j <= 700;j++)
        {
            while(zhi[j] != -1 && pk % zhi[j] == 0)
            {
                p[i][j]++;//j shi di  j ge zhi shu
                pk /= zhi[j];
            }
        }
    }
    cout << C(4,8);
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    return 0;
}

*/
