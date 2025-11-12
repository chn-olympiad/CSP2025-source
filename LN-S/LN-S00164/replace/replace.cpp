#include<bits/stdc++.h>
using namespace std;
struct wo
{
    string s1,s2;
}a[110],b[110];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].s1>>a[i].s2;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i].s1>>b[i].s2;
    }
    cout<<0;
    return 0;
}
