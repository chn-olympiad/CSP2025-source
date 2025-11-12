#include <bits/stdc++.h>
using namespace std;

string s;
long long cnt=0;
long long a[1000005];
bool cmp(long long a,long long b)
{
    return a>b;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size()-1;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            cnt++;
            a[cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
    {
        cout<<a[i];
    }

    return 0;
}
