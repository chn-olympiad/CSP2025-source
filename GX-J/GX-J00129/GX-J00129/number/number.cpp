#include<bits/stdc++.h>
using namespace std;
string a,b;
int n[5];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<=a.length()-1;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
            b[i]=a[i];
    }
    for(int i=0;i<b.length()-1;i++)
    {
        if(b[i]<b[i+1])
        {
            n[1]=b[i];
            b[i]=b[i+1];
            b[i+1]=n[1];
        }
        cout<<b[i];
    }
    return 0;
}
