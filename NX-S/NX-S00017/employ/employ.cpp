#include <bits/stdc++.h>
using namespace std;
int n,m,a[10000005],res;
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int l=1;
    for (int i=1;i<=n;i++)
    {
        if (a[i]!=0)
        {
            l=i;
            break;
        }
    }
    for (int s=1;l<=n;l++,s++)
    {
        res*=s;
        res%=998244353;
    }
    cout<<res;
}
