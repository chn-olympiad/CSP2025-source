#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,w="";
    int a[1000005];
    int cnt=0;
    cin>>s;
    int l=s.size();
    for(int i=1;i<=l;i++)
    {
        a[i]=-1;
    }
    for(int i=0;i<=l-1;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            cnt++;
            a[cnt]=int(s[i]-'0');
        }
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
    {
        cout<<a[i];
    }
    return 0;
}
