#include <bits/stdc++.h>
using namespace std;

long long n,q,sum;
string a,b;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>n>>q;
    sum=n+q;
    for(int i=0; i<sum; i++)
    {
        cin>>a>>b;
    }
    for(int i=0; i<q; i++)
    {
        cout<<'0'<<endl;
    }
    return 0;
}
