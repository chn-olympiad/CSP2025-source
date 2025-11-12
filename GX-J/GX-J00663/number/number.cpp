#include<bits/stdc++.h>
using namespace std;

int main ()
{

    freopen("number1.in","r",stdin);
    freopen("number1.out","w",stdout);

    string a;
    cin>>a;

    int num[a.length()],b=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]-48>=0 && a[i]-48<=9)
        {
            num[b]=a[i]-48;
            b++;
        }
    }

    sort(num,num+b);

    for(int i=b-1;i>=0;i--)
        cout<<num[i];

    return 0;
}
