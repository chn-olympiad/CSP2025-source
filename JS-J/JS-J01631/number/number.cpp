#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,b;
    int a=0;
    cin>>s;
    for(int i=0;i<=s.size();i++)
    {
        if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
        {
            a++;
            b[a]=s[i];
        }
    }
    for(int i=1;i<=a;i++)
        for(int j=1;j<=a;j++)
            if(b[j]>=b[j-1])swap(b[j],b[j-1]);
    for(int i=0;i<=a;i++)
    {
        cout<<b[i];
    }
    return 0;
}
