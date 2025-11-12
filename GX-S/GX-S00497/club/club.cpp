#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;
int t,n,aver,ans,cnt;
int a[100010][10],d[100010][100010];
//int a[100010];

int main()
{
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    cin >> t;

    while(t--)
    {
        cin >> n;
        aver = n / 2;ans = 0;cnt = 0;

        for(int i = 1;i <= n;i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        }

        for(int i = 1;i <= n;i++)
        {

            ans = max(ans,cnt);
        }
        cout << ans;
        cout << endl;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
