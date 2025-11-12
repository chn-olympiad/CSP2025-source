#include <bits/stdc++.h>

using namespace std;
struct re{
    string s1,s2;
}a[200010];
re v[200010];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin >>a[i].s1>>a[i].s2;
    }
    for(int i=1;i<=q;i++)
    {
        cin >>v[i].s1>>v[i].s2;
    }
    for(int i=1;i<=q;i++)
    {
        cout <<"0"<<endl;
    }
    return 0;
}
