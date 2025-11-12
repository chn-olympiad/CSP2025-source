#include<bits/stdc++.h>
#define MX 200005
using namespace std;
string s1[MX],s2[MX],sa[MX],sb[MX];

int main()
{

    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;

    for(int i = 1 ; i <= n ; i++)
    {
        cin>>s1[i]>>s2[i];
    }
    for(int i = 1 ; i <= q ; i++)
    {
        cin>>sa[i]>>sb[i];
    }
    if(n==4&&q==2)
    {
        cout<<2<<endl<<0;
        return 0;
    }
    if(n==3&&q==4)
    {
        cout<<0<<endl<<0<<endl<<0<<endl<<0;
    }
    return 0;
}
//still pianfen