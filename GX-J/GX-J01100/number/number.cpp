#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[100001],c=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[++c]=(int)(s[i]-'0');
        }
    }
    sort(a+1,a+1+c,cmp);
    for(int i=1;i<=c;i++)
    {
        cout<<a[i];
    }
    return 0;
}
