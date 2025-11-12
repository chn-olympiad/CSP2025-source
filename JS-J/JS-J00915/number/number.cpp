#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string s;
long long a[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--)
    {
        if(a[i]>=0)
        {
            while(a[i]--)printf("%d",i);
        }
    }
    return 0;
}
