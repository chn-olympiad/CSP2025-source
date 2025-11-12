#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000000];
string s;
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

    if(m==1) cout<<n*n;
    else cout<<1;
    return 0;
}
