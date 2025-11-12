#include <bits/stdc++.h>
using namespace std;
int cnt=1,a[1000010];
string str;
int mycmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>str;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            a[cnt]=str[i]-'0';
            cnt++;
        }
    }
    sort(a+1,a+cnt,mycmp);
    for(int i=1;i<cnt;i++)
    {
        cout<<a[i];
    }
    return 0;
}
