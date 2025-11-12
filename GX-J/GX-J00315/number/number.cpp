#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int ans[1000010];
int tmp=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<1000010;i++)
    {
        if(s[i]-'0'<16)
        {
            ans[tmp]=int(s[i]);
            tmp++;
        }
    }
    sort(ans,ans+tmp);
    for(int i=tmp-1;i>=0;i--)
    {
        cout<<char(ans[i]);
    }
    return 0;
}
