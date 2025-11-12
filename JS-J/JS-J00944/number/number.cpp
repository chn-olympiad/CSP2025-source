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
    int a[1000100];
    int cn=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            cn++;
            a[cn]=s[i]-'0';
        }

    }
    sort(a+1,a+cn+1,cmp);
    for(int i=1;i<=cn;i++)
    {
        cout<<a[i];
    }
    return 0;
}