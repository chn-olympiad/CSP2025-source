#include <bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
int cnt=0;
bool cmp(char x,char y)
{
    return x>=y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    /*
    qwq
    */
    cin>>s;
    for(int i=0;i<int(s.size());i++)
    {
        if(s[i]>='0' && s[i]<='9')
            a[++cnt]=s[i];
    }
    sort(a+1,a+1+cnt,cmp);
    for(int i=1;i<=cnt;i++)
        cout<<a[i];
    return 0;
}
