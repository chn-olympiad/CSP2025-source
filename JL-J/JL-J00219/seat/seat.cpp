#include<bits/stdc++.h>
using namespace std;
int a[100001],b[101][101];
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,num = 0,ans = 1;
    cin >> n >> m;
    for(int i = 1;i <= n*m;i ++)
    {
        cin >> a[i];
    }
    num = a[1];
    int j = 1;
    int i;
    int q = 1;
    sort(a+1,a+n*m+1,cmp);
    while(j <= m)
    {

        for(i = 1;i <= n;i ++)
        {
            b[i][j] = a[q];
            q ++;
        }
        j ++;
        for(i = n;i >= 1;i --)
        {
            b[i][j] = a[q];
            q ++;
        }
        j ++;

    }
    for(i = 1;i <= n;i ++)
    {

        for(j = 1;j <= m;j ++)
        {
            if(b[i][j] == num)
            {
                cout << j << ' ' << i;
            }
        }
    }
    return 0;
}
