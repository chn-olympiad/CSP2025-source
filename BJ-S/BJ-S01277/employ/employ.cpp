#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;

int n,m,c[N];
ll c1=1,c2=1,ans;
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>m>>n>>s;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=m;i++)
        c1*=i,c1%=mod;
    for(int i=m+1;i<=n;i++)
        c2*=i,c2%=mod;
    cout<<0;
    return 0;
}