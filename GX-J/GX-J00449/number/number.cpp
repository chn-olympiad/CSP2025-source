#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string a;
    int c[1000000];
    cin >> a;
    int b = a.length();

    for(int i=0;i<b;i++)
    {
        if('0'<=a[i]&&a[i]<='9')
        {
            c[i]=a[i]-48;

        }
    }
    for(int i=0;i<b;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(c[j]<c[j+1])
            {
                swap(c[j],c[j+1]);
            }
        }
    }

    for(int i=0;i<b;i++)
    {
        if('0'<=a[i]&&a[i]<='9')
        {
            cout << c[i];
        }
        }


    return 0;
}
