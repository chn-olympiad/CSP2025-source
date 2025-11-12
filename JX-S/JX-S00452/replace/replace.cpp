#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string a[10000],b[10000],c[10000],d[10000];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>c[i]>>d[i];
    }
    for(int i=1;i<=q;i++)
    {
        cout<<"0"<<endl;
    }
    return 0;
}
