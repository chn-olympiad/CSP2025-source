#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string a,b;
    cin >> a;

    for(int i=1;i<=a;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            b[i]=a[i];
        }
    }
    for(int i=1;i<=b;i++)
    {
        if(b[i]<b[i+1])
        {
            swap(b[i],b[i+1]);
        }
    }
    cout << b;
}
