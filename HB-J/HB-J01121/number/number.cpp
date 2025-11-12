#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int N=1e6+5;
char a[N];
string b;
int k;
void solve()
{
    cin>>b;
    for(int i=0;i<b.size();i++)
    {
        if('0'<=b[i]&&b[i]<='9')
        {
            a[++k]=b[i];
        }
    }
    sort(a+1,a+1+k);
    if(a[k]=='0'||k==0)cout<<0;
    else
    {
        for(int i=k;i>=1;i--)
        {
            cout<<a[i];
        }
    }
}
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}
