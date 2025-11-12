#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in",'r',stdin);
    freopen("number.out",'w',stdout);
    string a;
    int b[1000001],x=0;
    cin>>a;
    for(int i=0;a[i]!=' ';i++)
    {
        if(int(a[i]-'0')>=0&&int(a[i]-'0')<=9)
        {
            x++;
            b[x]+=a[i]-'0';
        }
    }
    sort(b+1,b+x+1);
    for(int i=x;i>=1;i--)
    {
        cout<<b[i];
    }
}
