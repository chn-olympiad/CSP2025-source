#include<bits/stdc++.h>
using namespace std;
int a[1000000];
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++)
    {
        cin >> a[i];
    }
    int grade = a[1];
    sort(a + 1,a + n * m + 1,cmp);
    int wz = 0;
    for(int i = 1;i <= n * m;i++)
    {
        if(grade == a[i])
        {
            wz = i;
        }
    }
    if(n % 2 != 0)
    {
        cout << (wz - 1) / n + 1 << " " << wz - ((wz - 1) / n * n) / m + 1;
    }
    else
    {
        cout << (wz - 1) / n + 1 << " " << wz - ((wz - 1) / n * n) / m + 2;
    }
    return 0;
}
