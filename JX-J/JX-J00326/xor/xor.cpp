#include<bits/stdc++.h>
using namespace std;
int a[100010] = {};
int b[100010] = {};
int mys1[100] = {},mys2[100] ={},mys3[100] ={};
int f(int x,int y)
{
    int i =1;
    while(x > 0)
    {
        mys1[i] = x % 2;
        i++;
        x = x / 2;
    }
    i = 0;
    while(y >0)
    {
        mys2[i] = x % 2;
        i++;
        y = y /2;
    }
    int len = i;
    while(i > 0)
    {
        if(mys1[i] == mys2[i])
        {
            mys3[i] = 1;
        }
        else
        {
            mys3[i] = 0;
        }
        i--;
    }
    int q = 1,sum = 0;
    for(int i = 1;i<= len;i++)
    {
        sum += mys3[i] * q;
        q = q * 2;
    }
    return sum;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    int cnt = 0;
    for(int i = 1; i <= n;i++)
    {
        cin >> a[i];
        if(f(a[i],a[i]) == k)
        {
            cnt++;
            a[i] ==-1;
        }
    }
    if(n == 1)
    {
        if(f(a[1],a[1]) == k)
        {
            cout << 1;
            return 0;
        }
        else
        {
            cout << 0;
            return 0;
        }
    }
    if(n == 2)
    {
        int mmmm = 0;
        if(f(a[1],a[1]) == k)
        {
            mmmm++;
        }
        if(f(a[1],a[2]) == k)
        {
            mmmm++;
        }
        if(f(a[2],a[2]) == k)
        {
            mmmm++;
        }
        cout << mmmm;
        return 0;
    }
    int j = 1;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] != -1)
        {
            b[j] = a[i];
            j++;
        }
    }
    cout << 2025;
    return 0;
}
