#include<bits/stdc++.h>
string s;
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    string d;
    string u;
    for(int i=s[0];i<=str(s);i++)
    {
        if(i<'65')
        {
            d+=i;
        }
    }
    int ans=str(d);
    int max_d;
    while(ans>=0)
        for(int j=d[0];j<=ans;j++)
        {
            max_d==j;
            if(d[j]>max_d)
            {
                max_d==d[j];
                u=u+max_d;
            }
                }
        d=d-d[j];
                ans--;
        }
    cout<<u;
    return 0;
}
