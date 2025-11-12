#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e3+10;
ll n,q,x[N];
string s1,s2;
string s[N][3];
ll f[N][N];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1>>s2;
        ll k=s[i][1].find('b'),k2=s[i][2].find('b');
        f[k-k2+1000][min(k,k2)]++;
    }
    for(int i=1;i<=1e3;i++)
    {
        for(int j=1;j<=4e3;j++)
        {
            f[j][i]+=f[j-1][i];
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>s1>>s2;
        ll k=s[i][1].find('b'),k2=s[i][2].find('b');
        cout<<f[k+1000][k2]<<"\n";
    }
}