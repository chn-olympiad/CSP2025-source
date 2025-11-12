#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N]={},cnt=0,t=0;
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        a[i]=int(s[i])-48;
        cnt++;
    }
    if(len!=1){
        sort(a,a+len-1);
    }
    else
    {
        cout<<s;
        return 0;
    }
    for(int i=len-1;i>=0;i--)
    {
        if(a[i]!=0)
        {
            cout<<a[i];
            t++;
        }
    }
    for(int i=1;i<=cnt-t;i++)
    {
        cout<<0;
    }
    return 0;
}
