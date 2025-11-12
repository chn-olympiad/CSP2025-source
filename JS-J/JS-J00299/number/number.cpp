#include <bits/stdc++.h>
using namespace std;
int ans[1002025],t;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(isdigit(s[i]))
        {
            t++;
            ans[t]=s[i]-48;
        }
    sort(ans+1,ans+t+1);
    for(int i=t;i>=1;i--) cout<<ans[i];
    cout<<endl;
    return 0;
}
