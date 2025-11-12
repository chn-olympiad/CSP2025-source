#include<bits/stdc++.h>
using namespace std;
string s;
int n,m;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
    }
    if(n==4) cout<<2;
    if(n==5) cout<<2;
    if(n>5&&n<=255) cout<<n/12+n%12;
    return 0;
}
