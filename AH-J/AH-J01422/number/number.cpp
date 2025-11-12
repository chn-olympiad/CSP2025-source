#include<bits/stdc++.h>
using namespace std;
string s;
int ans[100];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            int t=s[i]-'0';
            ans[t]++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=ans[i];j++)
        {
            cout<<i;
        }
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
