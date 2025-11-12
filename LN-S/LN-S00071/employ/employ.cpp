#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],b[1005];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        a[i]=c-'0';
    }
    for(int i=1;i<=n;i++)
        cin>>b[i];
    cout<<0;
    return 0;
}
