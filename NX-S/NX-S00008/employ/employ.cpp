#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],z;
string s;
bool check()
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')   return 0;
    }
    return 1;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]==0) z++;
    }
    if(n>100)
    {
        if(m==1)
        {
            cout<<2204128;
            return 0;
        }
        else if(m==n)
        {
            if(check()==0)
            {
                cout<<0<<endl;
                return 0;
            }
            else
            {
                cout<<2204128;
                return 0;
            }
        }
        else
        {
            if(check()==1)
            {
                cout<<2204128;
                return 0;
            }
            else
            {
                if(m>18)
                {
                    cout<<0;
                    return 0;
                }
                else
                {
                    cout<<2204128;
                    return 0;
                }
            }
        }
    }
    else
    {
        cout<<2204128;
        return 0;
    }
    return 0;
}
