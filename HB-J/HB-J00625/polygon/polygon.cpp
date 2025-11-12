#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,x,jg=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        jg+=x;
    }
    cout<<jg;
    return 0;
}

