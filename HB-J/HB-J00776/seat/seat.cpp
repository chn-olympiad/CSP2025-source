#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;


int n,m;
int a[15][15],b[108];
bool cmp(int a,int b)
{
    return  a > b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    int cj = n * m;
    int r = 0;
    for(int i = 1;i <= cj;i++)
    {
        cin >> b[i];
        r = b[1];
    }
    sort(b + 1,b + cj + 1,cmp);

    for(int j = 1,k = 0;j <= m;j++)
    {
            if(j % 2 == 1)
            {
                for(int i = 1;i <= n;i++)
                {
                    k++;
                    a[i][j] = b[k];

                }
            }
            else if(j % 2 == 0)
            {
                for(int i = n;i >= 1;i--)
                {
                    k++;
                    a[i][j] = b[k];

                }
            }
    }


    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <=m;j++)
        {
            if(a[i][j] == r)
            {
                cout << j << " " << i << endl;
                return 0;
            }
        }
    }
    return 0;
}
