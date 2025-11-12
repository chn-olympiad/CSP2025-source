#include<bits/stdc++.h>
using namespace std;
string s;int x;
int a[100005],cnt;
int main()
{
    freopen("number3.in","r",stdin);
    freopen("number2.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        x=s[i];
        if(x-48>=0 and x-48<=9)
        {
            a[i]=x-48;
            cnt++;
        }
    }
    sort(a,a+cnt+1);
    for(int i=cnt;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}


