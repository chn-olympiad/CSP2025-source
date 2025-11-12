#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a;
    string s;
    int b[10]={0,0,0,0,0,0,0,0,0,0};
    getline(cin,s);
    for(int i=0;i<s.size();i++)
    {
        a=s[i];
        int c=a-'0';
        if(c>=0&&c<=9) b[c]=b[c]+1;
    }
    for(int i=9;i>=0;i--)
    {
        for(long long k=1;k<=b[i];k++)
        {
            cout<<i;
        }

    }
    return 0;
}

