#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#define int long long
using namespace std;

int n,cnt;
string s;
const int N=1e6+10;
int a[N];

bool cmp(int a,int b)
{
    return a>b;
}

signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    s=" "+s;
    for(int i=1;i<=n;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[++cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+cnt+1,cmp);
    if(a[1]==0)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=cnt;i++)
    {
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
