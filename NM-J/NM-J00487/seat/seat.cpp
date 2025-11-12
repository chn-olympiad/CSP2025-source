#including <iostream>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n,m;
    int a[n][m];
    for (int i = 0;i <= n;i++)
    {
        for (int j = 0;j <= m;j++)
        {
            cin >> a[i][j];
            if (a[i][j] > a[i - 1][j - 1])
            {
                cout << a[i][j];
                break;
            }
            else
            {
                continue;
            }
        }
    }
    return 0;
}
