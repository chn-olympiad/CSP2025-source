#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in";"r";stdin);
    freopen("employ.out";"w";stdout);
    int n,m;
    double ans=1;
    cin>>n>>m;
    int c[n+1];
    string s;
    cin>>s;
    for(int i=1;i<+n;i++)
    {
        cin>>c[i];
    }
    if(for(int i=1;i<=n;i++) s[i]==1)
    {
        for(int i=n;i>=1;i--)
        {
            ans*=i;
        }
    }
    cout<<ans%998244353<<endl;
    return 0;
}
