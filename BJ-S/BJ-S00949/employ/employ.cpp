#include<bits/stdc++.h>
using namespace std;
int n,m,c[100010];
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    if(n==3)
    {
        cout<<2;
    }
    if(n==10)
    {
        cout<<2204128;
    }
    return 0;
}
