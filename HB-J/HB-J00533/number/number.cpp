#include <iostream>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int b[10000],n=0,d;
    cin>>a;
    for (int i=0;i<a.size();i++)
    {
        if (a[i]>='0' && a[i]<='9')
        {
            b[n]=int(a[i]-'0');
            n++;
        }
    }
    for (int j=0;j<n-1;j++)
    {
        for (int g=0;g<n-1;g++)
        {
            if (b[g]<=b[g+1])
            {
                d=b[g];
                b[g]=b[g+1];
                b[g+1]=d;
            }
        }
    }
    for (int m=0;m<n;m++)
    {
        cout<<b[m];
    }
    return 0;
}
