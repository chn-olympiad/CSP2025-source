#include<bits/stdc++.h>
using namespace std;
int t,n,mem1,mem2,mem3,ans,anstmp;
struct people
{
   int d1;
   int d2;
   int d3;
}a[100010];//存储满意度
void dfs(int x)
{
    if(mem1>n/2 || mem2>n/2 || mem3>n/2)
    {
        return ;
    }
    if(x>n)
    {
        ans = max(anstmp,ans);
        return ;
    }
    for(int i = 1;i<=3;i++)//三个部门
    {
        if(i == 1)
        {
            mem1++;
            anstmp += a[x].d1;
            dfs(x+1);
            anstmp -= a[x].d1;
            mem1--;
        }
        if(i == 2)
        {
            mem2++;
            anstmp += a[x].d2;
            dfs(x+1);
            anstmp -= a[x].d2;
            mem2--;
        }
        if(i == 3)
        {
            mem3++;
            anstmp += a[x].d3;
            dfs(x+1);
            anstmp -= a[x].d3;
            mem3--;
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for(int i = 1;i<=t;i++)
    {
        cin >> n;
        mem1 = 0; mem2 = 0 ; mem3 = 0;
        anstmp = 0,ans = 0;
        for(int j = 1;j<=n;j++)
        {
            cin >> a[j].d1 >> a[j].d2 >> a[j].d3;
        }
        dfs(1);
        cout << ans <<endl;
    }
    return 0;
}
