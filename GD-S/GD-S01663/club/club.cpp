#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int t,n,a[8][100005],temp,ans,maximum,num[8];
bool spa;
void dfs(int k)
{
    if(k>=n)
    {
        maximum=max(ans,maximum);
        return;
    }
    for(int i=0;i<3;i++)
    {
        if(num[i]+1<=n/2)
        {
            num[i]++;
            ans+=a[i][k];
            dfs(k+1);
            num[i]--;
            ans-=a[i][k];
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin >> t;
    for(int i=0;i<t;i++)
    {
        maximum=-1;
        ans=0;
        spa=1;
        cin >> n;
        for(int j=0;j<n;j++)
        {
            cin >> a[0][j] >> a[1][j] >> a[2][j];
            if(a[1][j]!=0||a[2][j]!=0)
            {
                spa=0;
            }
        }
        if(spa==1)
        {
            sort(a[0],a[0]+n);
            if(n%2==0)
            {
                temp=n/2;
            }
            if(n%2==1)
            {
                temp=n/2+1;
            }
            for(int j=n-1;j>=temp;j--)
            {
                ans+=a[0][j];
            }
            cout << ans << endl;
            continue;
        }
        dfs(0);
        cout << maximum << endl;
    }
    return 0;
}
