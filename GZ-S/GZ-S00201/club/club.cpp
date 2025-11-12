//GZ-S00201 赫章县西城区高级中学 晋宇轩
#include<bits/stdc++.h>
using namespace std;
int t , n , check , num[3] , ans[3];

int main()
{
    freopen("club.in" , "r" ,stdin);
    freopen("club.out" , "w" ,stdout);

    cin >> t;
    while(t--)
    {

        cin >> n;
        int a[n][3];
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<3;j++) cin >> a[i][j];
        }


        for (int i=0;i<n;i++)
        {
                if (a[1][i] > a[1][i]) swap(a[1][i] , a[1][i]);
        }
        for (int j=0;j<n;j++)
        {
                if (a[2][j] > a[2][j]) swap(a[2][j] , a[2][j]);
        }
        for (int k=0;k<n;k++)
        {
                if (a[3][k] > a[3][k]) swap(a[3][k] , a[3][k]);
        }


        for (int i = 0;i<n;i++)
        {
            for (int j=0;j<3;j++)
            {
                if (num[j] < n/2)
                {
                    ans[j] += a[i][j];
                    num[j]++;
                }
                else j++;
            }
        }

        for (int j=0;j<=3;j++) cout << ans[j] << endl;
    }

    return 0;
}
