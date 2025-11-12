#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],cnt;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>=48&&s[i]<59)
        {
            a[cnt]=s[i]-48;
            cnt++;
        }
    }
    sort(a,a+cnt,cmp);
    for(int i=0;i<cnt;i++)
    {
        cout<<a[i];
    }
}
