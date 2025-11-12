#include <bits/stdc++.h>
using namespace std;
string s;
int b[1000010];
int k,cnt;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    k=s.size();
    for(int i=0;i<=k;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            b[++cnt]=int(s[i]);
        }
    }
    sort(b+1,b+cnt+1);
    for(int i=cnt;i>=1;i--)
    {
        cout<<char(b[i]);
    }

    return 0;
}
