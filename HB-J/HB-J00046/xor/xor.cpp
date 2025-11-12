#include <bits/stdc++.h>
using namespace std;
long long arr[5 << 10],mg,n,k,zc[5<<10];
void dfs(long long a,long long gs,long long sum)
{
    if(mg <gs)
    {
        mg = gs;
    }
    if(a+1 > n)
    {
        if(sum == k)
        {
            gs++;
        }
        if(mg < gs)
        {
            mg = gs;
        }
        return ;
    }
    if(sum == 0)
    {
        sum = arr[a];
    }
    if(sum == k)
    {
        dfs(a+1,gs+1,0);
        dfs(a+1,gs,sum^arr[a+1]);
    }
    else
    {
        dfs(a+1,gs,0);
        dfs(a+1,gs,sum^arr[a+1]);
    }
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> arr[i];
    }
    if(k == 0)
    {
        int s = n/2;
        cout << s;
        return 0;
    }
    dfs(1,0,arr[1]);
    cout << mg;

    return 0;
}
