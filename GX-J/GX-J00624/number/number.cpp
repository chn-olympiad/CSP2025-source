#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    if (a>=b)
    {
        return b<=a;
    }
    else
    {
        return a>b;
    }
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a[100000];
    long long num[100000];
    cin >> a;
    long long n=strlen(a),mp=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]<='9' && a[i]>='0')
        {
            num[mp]=a[i]-'0';
            mp++;
        }
    }
    sort(num,num+mp,cmp);
    for (int i=0;i<mp;i++)
    {
        cout << num[i];
    }
    return 0;
}
