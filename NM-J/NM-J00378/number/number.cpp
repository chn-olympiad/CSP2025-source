#include <iostream>
#include <cstring>
#include <cstdio>
#define lli long long int
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    lli a[110]={0};
    string s;
    cin>>s;
    lli n=s.size();
    for(int i=0;i<=n;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[s[i]-'0']++;
        }

    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=a[i];j++)
        {
            cout<<i;
        }
    }
    return 0;
}
