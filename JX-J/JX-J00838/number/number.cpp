#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int l = s.size();
    for(int i = 9;i>=0;i--)
    {
        for(int j = 0;j<l;j++)
        {
            if(int(s[j])-48 == i)
            {
                cout<<s[j];
            }
        }
    }
    return 0;
}
