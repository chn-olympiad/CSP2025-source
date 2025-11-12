#include<iostream>
#include<algorithm>
using namespace std;

freopen("polygon.in", 'r', stdin);
freopen("polygon.out", 'w', stdout);

int cmp(int a, int b)
{
    return a < b;
}

int main()
{
    int n, a[5000], cnt = 9;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for (int i = 3; i < n; i++)
    {
        
    }
    cout << cnt;
    return 0;
}
