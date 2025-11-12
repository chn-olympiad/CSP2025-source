#include<bits/stdc++.h>
using namespace std;
int n,m;
long long sum=1;
string s;
int a[1001000],c[1001000];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[i]=i;
    }
    int l=1,r=n;
    for(int i=m;i<=n;i++)
    {
        sum*=c[r];
        sum/=c[l];
        r--;
        l++;
        sum%=998244353;
    }
    cout<<sum;
    return 0;
}
