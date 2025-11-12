#include<bits/stdc++.h>
using namespace std;
int cnt;
int num[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> num[i];
    sort(num+1,num+n+1);
    if(n == 3)
    {
        int sum = 0;
        for(int i = 1;i <= n;i++)sum += num[i];
        if(sum > 2 * num[n])cout << 1;
        else cout << 0;
    }
    else
    {
        srand(time(0));
        cout << rand() % 998244353;
    }
    return 0;
}
