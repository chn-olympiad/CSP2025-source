#include <bits/stdc++.h>
using namespace std;

int n,k,ans;
int a[500500];
bool b[2000][2000];
int dp[2000][2000];
int Sum[2000][2000];
int YI;
void Res(int I,int J)
{
    int ling = a[I];
    for(int i = I + 1;i <= J;i++)
    {
        ling ^= a[i];
    }
    if(ling == k)
    {
        b[I][J] = 1;
        ans++;
    }
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    YI = a[1];
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            Res(i,j);
        }
    }
    int S = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            Sum[i][j] = b[i][j] + b[i][j] * (b[i + 1][j] + b[i - 1][j] + b[i][j - 1] + b[i][j + 1]);
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(Sum[i][j] == 1)
            {
                S++;
            }
        }
    }

    cout << S;
    return 0;
}
//SYNB ShaoYuNB
