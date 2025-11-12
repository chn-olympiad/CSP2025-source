#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    char b[a.size()];
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='0'&&a[i]<='9')
            b[i]=a[i];
    }
    sort(b,b+a.size());
    for(int i=a.size()-1;i>=0;i--)
    {
        if(b[i]>='0'&&b[i]<='9')
            cout<<b[i];
    }
    return 0;
}
