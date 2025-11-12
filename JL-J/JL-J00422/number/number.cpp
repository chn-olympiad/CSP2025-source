#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000010];
int cnt=0;
bool cmp(char x,char y)
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
        if(s[i]>='0'&&s[i]<='9')
        {
            a[cnt]=s[i];
            cnt++;
        }
    }
    sort(a,a+cnt,cmp);
    for(int i=0;i<cnt;i++)cout<<a[i];
    return 0;
}
