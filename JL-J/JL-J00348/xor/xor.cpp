#include<bits/stdc++.h>
using namespace std;

int a[500001];

int s(int k,int g,int su,int n)
{
    if(g > n) return su;
    for(int i = 1;i <= n-g;i++)
    {
        if(a[i] == -1) continue;
        int sum = a[i];
        for(int j = i+1;j <= i+g;j++)
        {
            if(a[j] == -1) continue;
            sum += a[j];
        }
        if(sum/2+1 == k)
        {
            for(int j = i;j <= n;j++)
                a[j] = -1;
            su++;
        }
    }
    return s(k,g+1,su,n);
}

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,t = 0;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    int su = 0;
    if(k == 0)
    {
        for(int i = 1;i <= n;i++)
            if(a[i] == k)
                su++;
        cout << su;
        return 0;
    }
    for(int i = 1;i <= n;i++)
    {
        if(a[i]/2+1 == k)
        {
            a[i] = -1;
            su++;
        }
    }
    cout << s(k,1,su,n);
    return 0;
}
