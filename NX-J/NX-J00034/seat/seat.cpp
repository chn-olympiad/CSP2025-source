#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int all[225];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int cnt,ai;
    cnt = n*m;
    for(int i=1;i<= cnt;i++)
    {
        cin >> all[i];
        ai = all[1];
    }
    sort(all+1,all+cnt+1);
    for(int i=1;i<=cnt/2;i++) swap(all[i],all[cnt+1-i]);
    //for(int i=1;i<=cnt;i++) cout << all[i] << endl;
    for(int j=1;j<=m;j++)
    {
        if(j%2 == 0)
        {
            int t =n*(j-1)+1;
            for(int i=n;i>=1;i--)
            {
                a[i][j] = all[t];
                t++;
                if(a[i][j]==ai) cout << j << ' ' << i << endl;
            }
        }
        else if(j%2 != 0)
        {
            int t=n*(j-1)+1;
            for(int i=1;i<=n;i++)
            {
                a[i][j] = all[t];
                t++;
                if(a[i][j]==ai) cout << j << ' ' << i << endl;
            }
        }
    }
    return 0;
}
