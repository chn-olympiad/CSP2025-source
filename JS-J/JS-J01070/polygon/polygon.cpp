#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","r",stdout);
    int n,x,num=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        num+=x;
    }
    cout<<num;
    return 0;
}
