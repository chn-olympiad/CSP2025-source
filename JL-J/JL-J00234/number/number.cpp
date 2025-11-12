#include<bits/stdc++.h>
using namespace std;
string a;
char b[1000005];
int n;
int main()
{

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i = 0;i<a.length();i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            b[i]=a[i];
            n++;
        }
    }
    if(n==1)
    {
        cout<<b[0];
    }
    else if(n==2)
    {
        if(b[0]>b[1])
        {
            cout<<b[0]<<b[1];
        }
        else
        {
            cout<<b[1]<<b[0];
        }
    }
    return 0;
}
