#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int xx[1000001]={0},x=0;
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(int(a[i])>=48&&int(a[i])<=57)
        {
            x++;
            xx[x]=int(a[i]-'0');
        }
    }
    sort(xx+1,xx+1+x);
    for(int i=x;i>=1;i--)
    {
        cout<<xx[i];
    }
    return 0;
}
