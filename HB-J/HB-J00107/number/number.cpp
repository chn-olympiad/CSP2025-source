#include <bits/stdc++.h>
using namespace std;
string input;
string str[10];
char ch;
int main()
{
    for (int i=0;i<=9;++i)
        str[i]="";
    cin>>input;
    long long len=input.size();
    for (int i=0;i<len;++i)
    {
        if ('0'<=input[i]&&input[i]<='9')
            str[input[i]-'0']+=input[i];
    }
    for (int i=9;i>=0;--i)
        cout<<str[i];
    return 0;
}