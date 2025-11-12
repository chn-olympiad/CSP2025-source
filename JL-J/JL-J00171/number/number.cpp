#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a,c;
    int b=0;
    cin>>a;
    for(int i=0;i<=a.size();i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            c[b]=a[i];
            b++;
        }
    }
    for(int i=b;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(c[j]<c[j+1])
            {
                swap(c[j],c[j+1]);
            }
        }
    }
    for(int i=1;i<=b;i++)
    {
        cout<<c[i];
    }
    return 0;
}
