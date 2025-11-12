#include<bits/stdc++.h>
using namespace std;
string a;
int b[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<=a.size();i++)
    {
        int c=a[i]-'0';
        if(c>=0&&c<=9)
            b[c]++;
    }
    for(int i=9;i>=0;i--)
    {
        while(b[i]--)
            cout<<i;
    }
    return 0;
}
