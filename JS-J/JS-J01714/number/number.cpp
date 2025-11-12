#include<bits/stdc++.h>
using namespace std;
string mys;
int a[1000005];
int n;
int sum;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>mys;
    n=mys.size();
    for (int i=0;i<n;i++)
    {
        if (mys[i]>='0' && mys[i]<='9')
        {
            a[sum]=mys[i]-'0';
            sum++;
        }
    }
    sort(a,a+sum);
    for (int i=sum-1;i>=0;i--)
    {
        cout<<a[i];
    }
    return 0;
}
