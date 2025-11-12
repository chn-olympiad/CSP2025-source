#include <bits/stdc++.h>
using namespace std;
int maxn(int n,int m)
{
    int num=10;
    while (m>n%num)
    {
        num*=10;
    }
    return (sum-sum%num)*10+n*num;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int sum=0;
    for (int i=0;i<a.stor();i++)
    {
        if (a[i]>='0' && a[i]<='9')
        {
            sum=maxn(sum,a[i]);
        }
    }
    cout<<sum;
    return 0;
}
