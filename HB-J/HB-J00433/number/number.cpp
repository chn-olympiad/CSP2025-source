#include<bits/stdc++.h>
using namespace std;
string s;
int len,a[1000010],j=-1;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    len=s.size();
    for(int i=0;i<len;i++)
    {
        s[i]=s[i]-'0';
        if(0<=s[i]&&s[i]<=9)
        {
            j++;
            a[j]=s[i];
        }
    }
    sort(a,a+j,cmp);
    for(int i=0;i<=j;i++)
    {
        cout<<a[i];
    }
    return 0;
}
