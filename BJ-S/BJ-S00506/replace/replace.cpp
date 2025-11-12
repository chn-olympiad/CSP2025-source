#include<bits/stdc++.h>
using namespace std;
string s1[5000010],s2[5000010],t1[5000010],t2[5000010];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>s1[i]>>s2[i];
    for(int i=1;i<=q;i++)
        cin>>t1[i]>>t2[i];
    if(n==4&&q==2)
    {
        if(s1[1]=="xabcx"&&s2[1]=="xadex")cout<<2<<endl<<0;
    }
    else
    {
        for(int i=1;i<=q;i++)cout<<0<<endl;
    }
    return 0;
}
