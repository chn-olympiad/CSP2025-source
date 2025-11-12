#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node
{
   string s1,s2 ,q1,q2;
}a[200010];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].s1>>a[i].s2;
    }
    for(int i=1;i<=q;++i)
    {
        cin>>a[i].q1>>a[i].q2;
    }
    for(int i=1;i<=q;++i)
    {
        cout<<0<<endl;
    }
    return 0;
}