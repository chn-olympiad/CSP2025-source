#include<bits/stdc++.h>
using namespace std;
string s;
int ans[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>s;
    int d=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            ans[d]=s[i]-'0';
            d++;
        }
    }
    sort(ans+0,ans+d);
    for(int i=d-1;i>=0;i--)
    {
        cout<<ans[i];

    }

    return 0;
}
