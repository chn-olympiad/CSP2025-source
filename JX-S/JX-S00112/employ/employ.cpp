#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
string s;
int a[10006];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        sum*=i;
    }
    cout<<sum;
    return 0;
}
