#include <iostream>
#include <algorithm>
using namespace std;
const long long N = 5 * 1e3 + 5;
long long cnt = 0;
long long a[N];
long long sa[N];
void dfs(long long up_step,long long up_sum,long long step,long long sum)
{
        if(sum > up_sum) return;
        if(step > up_step && sum <= up_sum)
        {
                cnt++;
                return;
        }
        dfs(up_step,up_sum,step+1,sum);
        dfs(up_step,up_sum,step+1,sum + a[step]);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n; 
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(int i = 1 ; i <= n ; i++) sa[i] = sa[i-1] + a[i]; 
    for(long long i = 1 ; i <= n ; i++)
    {
        if(sa[i] <= a[i] * 2) continue; 
        long long sum = sa[i] - a[i] * 2 - 1;
        dfs(i-1,sum,1,0);
    }
    cout << cnt << endl; 
    return 0;
}
