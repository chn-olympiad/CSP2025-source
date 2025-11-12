#include <bits/stdc++.h>
using namespace std;
string a;
long long b[1000005],x=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='0' && a[i]<='9')
        {
            x++;
            b[x]=a[i]-'0';
        }
    }
    sort(b+1,b+x+1);
    for(int i=x;i>=1;i--)
    {
        cout<<b[i];
    }
    return 0;
}
