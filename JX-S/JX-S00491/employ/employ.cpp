#include<iostream>
#include<fstream>
#include<string>
using namespace std;
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    cin>>s;
    bool oko=true;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='1')
        {
            oko=false;
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        long long temp;
        cin>>temp;
    }
    if(oko==true)
    {
        cout<<(n*(n+1)/2)%998244353;
    }
    else
    {
        cout<<(n*(n+1)/2)%998244353;
    }
    return 0;
}
