#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int> a;
    for(int i=0;i<=s.size()-1;i++)
    {
        if(isdigit(s[i]))
        {
            a.push_back(s[i]-48);
            for(int j=0;j<=i;j++)
            {
                if(a[j]<s[i]-48)
                {
                    swap(a[j],a[a.size()-1]);
                    break;
                }
            }
        }
    }
    for(int i=0;i<=a.size()-1;i++)
    {
        cout<<a[i];
    }
    return 0;
}
