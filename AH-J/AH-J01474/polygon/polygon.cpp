#include <bits/stdc++.h>
using namespace std;
int main()
{
    int b=0;
    string a,c;
    cin>>b;
    for (int i=1;i<=b;i++)
    {
        cin>>c;
        a+=c;
    }
    for (int i=1;i<=b;i++)
    {
        for (int j=i+1;j<=b;j++)
        {
            if (a[i]<=a[j])
            {
                int d=a[i];
                a[i]=a[j];
                a[j]=d;
            }
        }
    }
    for (int i=1;i<=b-2;i++)
    {
        for (int j=b;j>=3;j--)
        {
            if ()
        }
    }
    return 0;
}
