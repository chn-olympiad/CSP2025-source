#include <bits/stdc++.h>
using namespace std;
int main()
{

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s="";
    cin>>s;

    int a[10]={0};
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            a[s[i]-'0']++;

        }
    }
    for(int i=9;i>=0;i--)
    {
        if(a[i]!=0)
        {
            for(int y=0;y<a[i];y++)
            {
                cout<<i;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
