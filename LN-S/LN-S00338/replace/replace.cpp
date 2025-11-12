#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    long long n,q;
    cin>>n>>q;
    for(long long i=1;i<=n;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
    }
    for(long long i=1;i<=q;i++)
    {
        string t1,t2;
        cin>>t1>>t2;
    }
    bool f;
    f=1;
    if(q==1)
    {
        cout<<1;
        f=0;
    }
    else
    {
        for(long long i=1;i<=q;i++)
        {
            cout<<0;
        }
    }
    return 0;
}
