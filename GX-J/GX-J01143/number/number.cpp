#include<bits/stdc++.h>
using namespace std;
long long ans[1000001];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    long long gs=0;
    getline(cin,s);
    for(long long i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            gs++;
            ans[gs]=(int)(s[i])-'0';
        }
    }
    sort(ans+1,ans+1+gs);
    for(long long i=gs;i>=1;i--)
    {
        cout<<ans[i];
    }
    return 0;
}
