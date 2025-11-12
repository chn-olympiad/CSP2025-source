#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[105],b[15][15];
    for(int i = 1;i <= n * m;i++)
    {
        cin >> a[i];
    }
    int s = a[1],cnt = 0;
    bool flag = false;
    sort(a + 1,a + n * m + 1,cmp);
    for(int i = 1;i <= m;i++)
    {
        flag = !flag;
        if(flag)
        {
            for(int j = 1;j <= n;j++)
            {
                cnt++;
                if(a[cnt] == s)
                    cout << i << " " << j;
            }
        }
        else
        {
            for(int j = n;j >= 1;j--)
            {
                cnt++;
                if(a[cnt] == s)
                    cout << i << " " << j;
            }
        }
    }
    return 0;
}
