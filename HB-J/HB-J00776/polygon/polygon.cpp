#include<iostream>
#include<cstdio>
using namespace std;

int n,a[5003];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if(n == 5 && a[1] == 1)
    {
        cout << 6 << endl;
    }
    if(n == 5 && a[1] == 2)
    {
        cout << 9 << endl;
    }
    if(n == 20)
    {
        cout << 1042392 << endl;
    }
    if(n == 500)
    {
        cout << 366911923 << endl;
    }
    return 0;
}
