#include <bits/stdc++.h>
using namespace std;
string s;
int ans[2000000+100];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int q=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            ans[q]=s[i]-'0';
            q++;
        }
    }
    s.clear();
    sort(ans,ans+q);
    for(int i=q-1;i>=0;i--)
    {
        cout << ans[i];
    }
    cout <<endl;

    return 0;
}