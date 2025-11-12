#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[10001]={0};
    int len=s.size(),alen=0;
    for(int i=0;i < len;i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            a[alen++]=(int)s[i]-'0';
        }
    }
    sort(a,a+alen,cmp);
    for(int i=0;i < alen;i++)
    {
        cout<<a[i];
    }
    return 0;
}
