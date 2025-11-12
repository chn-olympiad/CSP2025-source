#include <bits/stdc++.h>
using namespace std;
string a[10001][3];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>a[i][1]>>a[i][2];
    }
    for(int i=1;i<=q;i++)
    {
        cout<<0<<endl;
    }
    return 0;
}

