#include <iostream>
using namespace std;
int c,r,a[105],b[15][15];
int main()
{
    cin >> c >> r;
    for (int i = 1;i <= c*r;i++)
    {
        cin >> a[i];
    }
    int maxn=a[1];
    for (int i = 1;i <= c*r;i++)
    {
    	if (maxn<a[i])
    	{
    	   maxn=a[i];
    	}
    }
    for (int i = 1;i <= c;i++)
    {
        if (c%2==1)
        {
            for (int j = 1;j <= 2;j++)
            {
               b[i][j]=a[i];
            }
        }
        else
        {
            for (int j = 2;j >= 1;j--)
            {
               b[i][j]=a[r-j+1];
            }
        }
    }
    cout << b[c][r];
    return 0;
}
