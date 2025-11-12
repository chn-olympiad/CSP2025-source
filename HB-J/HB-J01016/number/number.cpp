#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string s;
int a[10],con,sdn,an = 0;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>'0' && s[i]<='9')
        {
            a[an++] = s[i] - '0';
            sdn++;
        }
        else if(s[i]=='0') con++;
    }
    if(sdn==0)
    {
        cout << 0;
        return 0;
    }
    sort(a,a+sdn);
    for(int i=sdn-1;i>=0;i--) cout << a[i];
    for(int i=1;i<=con;i++) cout << 0;
    return 0;
}
