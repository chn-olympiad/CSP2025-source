#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int c=0,d;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        d=(int)s[i];
        if(d>=48 && d<=57)
        {
            c++;
            a[c]=s[i];
        }
    }
    sort(a+1,a+c+1);
    for(int i=c;i>=1;i--)
    {
        cout<<(char)a[i];
    }
    return 0;
}

