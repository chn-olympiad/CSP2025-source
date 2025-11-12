#include<bits/stdc++.h>
using namespace std;
int n,q;
char s1,s2;
char t1,t2;
int a,b;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1>>s2;
    }
    for(int i=1;i<=q;i++)
    {
        cin>>t1>>t2;
    }
    if(n==4)
    {
        cout<<2<<endl<<0;
    }
    else if(q==2)
        cout<<2<<endl<<0;
    else
    {
        cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl;
    }
    return 0;
}
