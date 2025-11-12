#include <bits/stdc++.h>
using namespace std;
string s,g="0123456789";
char h;
int j,x[13],sum=0;
char k(char m)
{
    j=-1;
    for (int i=0;i<=9;i++)
    {
        if (m==g[i])
        {
            j=i;
            break;
        }
    }
    return j;
}
int main()
{
    freopen('number.in','r',stdin);
    freopen('number.out','w',stdout);
    cin >> s;
    for (int i=1;i<=sizeof(s);i++)
    {
        if (k(s[i-1])!=-1)
        {
            x[j]++;
        }
    }
    for (int l=9;l>=0;l--)
    {
        while (x[l]!=0)
        {
            sum=sum*10+l;
            x[l]--;
        }
    }
    cout << sum;
    return 0;
}
