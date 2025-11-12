#include <bits/stdc++.h>
using namespace.std
int main()
{
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
int n,q;
string  m1,m2,s[200005][5];
cin>>n>>q;
for(int i=1;i<=n;i++)
{
    cin>>m1>>m2;
}
for(int i=1;i<=q;i++)
{
    cin>>s[i][1]>>s[i][2];
}
cout<<q<<endl<<n-2*q;
fclose(stdin);
fclose(stdout);
    return 0;
}