#include<iostream>
#include<string>
using namespace std;
int c[510];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]=='0')
        {
            cnt++;
        }
    }
    bool flag=true;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='1')
        {
            flag=false;
        }
    }
    if(flag)
    {
        int mul=1;
        for(int i=1;i<=n-cnt;i++)
        {
            mul*=i;
            mul%=998244353;
        }
        if(m<n-cnt)
        cout<<mul<<endl;
        else
            cout<<0<<endl;
        return 0;
    }

    return 0;
}
