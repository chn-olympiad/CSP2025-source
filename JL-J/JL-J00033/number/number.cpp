#include <bits/stdc++.h>
using namespace std;
string a;
long long m,n,b[100+10],c,d;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    m=s.size();
    for(int i=1;i<=m;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            c++;
            b[c]=a[i];
        }
    }
    sort(b,b+1+c);
    for(int i=1;i<=c;i++)
    {
        cout<<b[i];
    }
    return 0;
}
