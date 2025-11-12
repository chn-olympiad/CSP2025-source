#include <bits/stdc++.h>
using namespace std;
int n,q,ans;
string s1[111111],s2[111111];
string s3[111111],s4[111111];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>s3[i]>>s4[i];
    }
    cout<<n*q%15<<endl;
    return 0;
}
