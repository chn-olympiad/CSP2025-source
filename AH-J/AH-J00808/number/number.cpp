#include<bits/stdc++.h>
using namespace std;
//a=97;
//z=122;
bool cmp(int a,int b)
{
    return a>b;
}
string str;
int a[1000050];
int top;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>str;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]>=97&&str[i]<=122)
        {
            continue;
        }
        else
        {
            a[top]=str[i]-48;
            top++;
        }
    }
    sort(a,a+top,cmp);
    for(int i=0;i<top;i++)
    {
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}
