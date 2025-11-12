#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","r",stdout);
    int n,m;
    long long mul=1;
    cin>>n>>m;
    for(int i=m+1;i<=n;i++)
    {
        mul*=i;
    }
    cout<<mul<<endl;
    return 0;
}