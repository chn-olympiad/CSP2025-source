#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1000001];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int ls=s.size();
    int len=0;
    for(int i=0;i<ls;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[++len]=s[i]-'0';
        }
    }
    sort(a+1,a+1+len,cmp);
    for(int i=1;i<=len;i++)
    {
        cout<<a[i];
    }
    return 0;
}
