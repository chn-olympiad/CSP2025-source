#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>> n >>m;
    if(m==n)
    {
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                cout <<0<< endl;
                return 0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>> x;
            if(x==0)
            {
                cout<<0 <<endl;
                return 0;
            }
        }
    }
    long long ans=1;
    for(int i=1;i<=n;i++)
    {
        ans=ans*i;
        ans%=998244353;
    }
    cout << ans << endl;
    return 0;
}
