#include<bits/stdc++.h>
using namespace std;
bool sol(int a,int b)
{
    if(a * 2 > b)
    {
        return false;
    }
    else return true;
}
struct Asd{
    int b;//sum
    long long c;//num
}a[5001][5001];
long long n,h,b[5001],p;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n;i++)
    {
        cin >> b[i];
    }
    sort(b + 1,b + n + 1);
    for(int i = n;i >= 1;i--)
    {
        for(int j = i + 1;j <= n;j++)
        {
            a[i][j].c = a[i][j - 1].c;
            a[i][j].b = b[j] + b[i];
            for(int k = i + 1;k < j;k++)
            {
                int num = 0;
                p = b[1];
                int y,z;
                y = 1;
                z = 1;
                while(1)
                {
                    if(p < b[j])
                    {
                        if(z < k)
                        {
                            z++;
                            p += b[z];
                        }
                        else break;
                    }
                    else
                    {
                        if(y - z > 2)
                        {
                            y--;
                        }
                        else
                        {
                            if(z < k) z++;
                            else break;
                            p += b[z];
                        }
                        num++;
                    }
                }
                a[i][j].c += a[k][j].c;
                a[i][j].c += num;
            }
        }
    }
    cout << a[1][n].c;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

