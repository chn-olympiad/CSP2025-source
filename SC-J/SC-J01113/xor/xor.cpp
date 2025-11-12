#include <iostream>
#include <algorithm> 
#include <cstring>
using namespace std;
const long long N = 5 * 1e5 + 5;
long long num[N];
long long a[N];
struct Stu
{
    long long b,e;
}g[N];
bool cmp(Stu x,Stu y)
{
    if(x.e != y.e) return x.e < y.e;
    return x.b > y.b;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++) cin >> num[i];
    for(int i = 1 ; i <= n ; i++)
    {
        long long res = num[i];
        if(res == k)
        {
            a[i] = i;
            continue;
        }
        for(int j = i + 1 ; j <= n ; j++)
        {
            res = res ^ num[j];
            if(res == k)
            {
                a[i] = j;
                break;
            }
        }
    }
    long long cur = 0;
    for(int i = 1 ; i <= n ; i++) 
    {
         if(a[i] != 0)
         {
             cur++;
             g[cur].b = i;
             g[cur].e = a[i];
        }
    }
    if(cur == 0)
    {
        cout << "0" << endl;
        return 0;
    }
    sort(g+1,g+cur+1,cmp);
    long long cnt = 1;
    long long end = g[1].e;
    for(int i = 2 ; i <= cur ; i++)
    {
        if(g[i].b > end)
        {
            cnt++;
            end = g[i].e;
        }
    }
    cout << cnt << endl;
    return 0;
}