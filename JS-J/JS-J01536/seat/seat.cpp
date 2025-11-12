#include<bits/stdc++.h>
using namespace std;
int a[105];
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
    int se = a[1];
    int num;
    sort(a + 1,a + n * m + 1,cmp);
    for(int i = 1;i <= n * m;i++)
    {
        if(a[i] == se)
        {
            num = i;
        }
    }
    int lie = ceil(num * 1.0 / n);
    if(lie % 2 == 1)
    {
        cout << lie << " " << (num + n - lie * n);
    }
    else
    {
        cout << lie << " " << (lie * n - num + 1);
    }
    return 0;
}
//9:04
