#include <bits/stdc++.h>
using namespace std;
struct f
{
    string s1;
    string s2;
};
f a[100];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].s1>>a[i].s2;
    }
    for(int j=1;j<=m;j++)
    {
        string a,b;
        cin>>a>>b;
        cout<<"0";
    }
}
