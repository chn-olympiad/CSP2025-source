#include<bits/stdc++.h>
using namespace std;
int a[500],ans,n,m,no,ok;
bool qq[500];
string s;
long long jiecheng(int a)
{
    long long ans=1;
    for(int i=1;i<=a;i++)
    {
        ans*=i;
        ans%=998244353;
    }
    return ans;
}
int main()
{
    freopen("employ3.in","r",stdin);
    freopen("employ3.out","w",stdout);
    cin>>n>>m;
    cout<<jiecheng(n);
    return 0;
}
