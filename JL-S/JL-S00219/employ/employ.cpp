#include <bits/stdc++.h>
using namespace std;
int a,b;
string s;
int aa[11111111];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>a>>b;
    getline(cin,s);
    for(int i=1;i<=a;i++)
    {
        cin>>a[i];
    }
    cout<<a*b%15;
    return 0;
}
