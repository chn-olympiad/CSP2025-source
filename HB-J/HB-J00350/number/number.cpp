#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;

string s,s_="";
int len,cnt=0,f=1;
int a[N];

bool cmp(int a,int b)
{
    return a>b;
}

int main(void)
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    len=s.length();
    for(int i=0;i<len;i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            a[++cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+1+cnt,cmp);
    while(f<cnt && a[f]==0) f++;
    for(int i=f;i<=cnt;i++)
    {
        cout<<a[i];
    }
    return 0;
}
