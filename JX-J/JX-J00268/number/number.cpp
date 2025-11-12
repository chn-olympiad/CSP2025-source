#include<bits/stdc++.h>
using namespace std;
string s;
char a[10000005];
int wei;
bool cmp(char l,char r)
{
    return l>r;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
                a[wei]=s[i];
                wei++;
        }
    }
    sort(a,a+wei,cmp);
    for(int i=0;i<wei;i++)
    {
        cout<<a[i];
    }
    return 0;
}
