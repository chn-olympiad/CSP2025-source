#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cup(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int len=0;
    for(int i=0;i<=s.size()-1;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            len++;
            a[len]=s[i]-'0';
        }
    }
    sort(a+1,a+len+1,cup);
    for(int i=1;i<=len;i++)
    {
        cout<<a[i];
    }
    return 0;
}
