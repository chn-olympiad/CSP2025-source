#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[1000005],cnt=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if((s[i]>='0')&&(s[i]<='9'))
        {
            a[i]=s[i]-'0';
            cnt++;
        }
    }
    int n=s.size();
    sort(a,a+n,cmp);
    for(int i=0;i<cnt;i++)
    {
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}
