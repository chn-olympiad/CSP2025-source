#include <iostream>
#include <algorithm>
using namespace std;

int a[5][100005], n, ans = 0;

void f(int x, int sum, int m1, int m2, int m3)
{
    if(m1 > n/2 ||m2 > n/2 || m3 > n/2) return;
    if(x > n)
    {
        ans = max(ans, sum);
        return;
    }
    //1
    f(x+1, sum+a[1][x], m1+1, m2, m3);
    //2
    f(x+1, sum+a[2][x], m1, m2+1, m3);
    //3
    f(x+1, sum+a[3][x], m1, m2, m3+1);
}
bool cmp(int x, int y)
{
    return x > y;
}
bool checka()
{
    for(int i = 1; i <= n; i++)
    {
        if(a[3][i] != 0 || a[2][i] != 0) return false;
    }
    return true;
}
bool checkb()
{
    for(int i = 1; i <= n; i++)
    {
        if(a[3][i] != 0) return false;
    }
    return true;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >>t;
    while(t--)
    {
        ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >>a[1][i] >>a[2][i] >> a[3][i];
        }
        if(checka()){
            //cout << "A: ";
            sort(a[1]+1, a[1]+n+1, cmp);
            int sum = 0;
            for(int i = 1; i <= n/2; i++)
            {
                sum += a[1][i];
            }
            cout << sum;
        }else if(checkb()){
            //
        }else{
            f(1, 0, 0, 0, 0);
            cout << ans <<endl;
        }
    }
    return 0;
}
