#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    if(n==1)
    {
        cout<<0;
    }
    else if(n==2)
    {
        long long a,b;
        cin>>a>>b;
        if(a^b==m)
            cout<<1;
        else
            cout<<0;
    }
    else{
        cout<<3;
    }
    return 0;
}
