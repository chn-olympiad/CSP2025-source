#include<bits/stdc++.h>
using namespace std;
int n,m,i;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    long long all=1;
    for(i=n;i>0;i--)
        all=all*i;
    cout<<all;

    return 0;
}
