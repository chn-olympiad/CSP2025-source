#include <bits/stdc++.h>
using namespace std;
int z[999999];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,b;
    int a,n;
    cin >> s;
    for (int i=0;i<=s.size()-1;i++)
    {
        if (s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
            b+=s[i];
    }
    for (int i=0;i<=b.size()-1;i++)
    {
        if (b[i]=='9')
            z[i]=9;
        else if (b[i]=='8')
            z[i]=8;
        else if (b[i]=='7')
            z[i]=7;
        else if (b[i]=='6')
            z[i]=6;
        else if (b[i]=='5')
            z[i]=5;
        else if (b[i]=='4')
            z[i]=4;
        else if (b[i]=='3')
            z[i]=3;
        else if (b[i]=='2')
            z[i]=2;
        else if (b[i]=='1')
            z[i]=1;
        else if (b[i]=='0')
            z[i]=0;
    }
    for (int i=0;i<=b.size()-1;i++)
    {
        for (int j=i;j<=b.size()-1;j++)
            if (z[j]<z[j+1])
            {
                n=z[j];
                z[j]=z[j+1];
                z[j+1]=n;
            }
    }
    for (int i=0;i<=b.size()-1;i++)
    {
        cout << z[i];
    }
}
