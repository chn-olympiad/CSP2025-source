#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],cnt;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    cnt=0;
    int l=s.length();
    for (int i=0;i<l;i++)
    {
        if ('0'<=s[i] && s[i]<='9')
        {
            cnt++;
            a[cnt]=s[i]-'0';
            
        }
    }

    sort(a+1,a+cnt+1);
    if (a[cnt]==0)
    {
        cout<<0;
    }else
    {
        for (int i=cnt;i>=1;i--)
        {
            cout<<a[i];
        }
    }
	return 0;
}
