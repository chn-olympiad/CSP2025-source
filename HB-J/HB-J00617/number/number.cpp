#include<bits/stdc++.h>
using namespace std;
string s;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            s.erase(i);
        }

    }
    string x=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<=n;i++)
        {
            if(s[j]>s[x])
            {
                x=j;
            }

        }
        swap(s[i],s[x]);

    }
    cout<<s;
    return 0;
}
