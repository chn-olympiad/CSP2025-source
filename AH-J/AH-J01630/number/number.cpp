#include<bits/stdc++.h>
using namespace std;
string s;
char a[100001];
int len=1;
bool cmp(char a,char b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            a[len]+=s[i],len++;
    }
    sort(a+1,a+1+len,cmp);
    for(int i=1;i<=len;i++)
    {
        cout<<a[i];
    }
    return 0;
}
