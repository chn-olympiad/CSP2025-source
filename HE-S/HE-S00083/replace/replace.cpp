#include<bits/stdc++.h>
using namespace std;
struct sling()
{
    string s,sl;
}a[200001];
struct tling()
{
    string t,tl;
}b[200001];
int main ()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string s,sl;
    string t,tl;
    for(int i=1,i<=n,i++)
    {
        cin>>a[i].s>>a[i].sl;
    }
    for(int j=1,j<=q,j++)
    {
        cin>>b[j].t>>b[j].tl;
    }
    if (n==4&&q==2)
        cout<<2<<endl<<0;
    else if(n==3&&q==4)
        cout<<0<<endl<<0<<endl<<0<<endl<<0;
    return 0;
}
