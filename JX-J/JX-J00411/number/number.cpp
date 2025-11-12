#include<bits/stdc++.h>
using namespace std;
string s;
char s2[1000000];
long long i2;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
        {
            s2[i2]=s[i];
            i2++;
        }
    }
    sort(s2,s2+s.length(),cmp);
    cout<<s2;
}
