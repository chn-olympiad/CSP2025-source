#include<bits/stdc++.h>
using namespace std;
int a[100005][3];
int b[100005][5];
int n, m, k, minn = INT_MAX, q, e;

int dp(int x, int y)
{

}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >>k;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j<= 3; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j<= 5; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= m; i++)
    {
        if(a[i][3] < minn)
        {
            minn += a[i][3];
            a[i][1] = 0;
            a[i][2] = 0;
        }
    }
    for(int i = 1; i <= k; i++)
    {
        for(int j =2; j <= 5; j++)
        {
            if(b[i][1] + b[i][j] < minn)
            {
                minn += b[i][1] + b[i][j];
                q = m + i;
                e = j;
            }
        }
    }
    cout << minn;



    return 0;
}
