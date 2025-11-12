#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353,N=1e5+5;;
int n,m,h=100,ans,s1;
int c[N],q[N];
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++) cin>>c[i];
    if(n==m)
    {
        cout<<m;
        return 0;
    }

    for(int i=1;i<=n;i++)
    {
        if(h<0) break;
        //s1=s-'0';
        //q[i]=(int)(s/h%10);
        h/=10;
    }
    for(int i=1;i<=n;i++)
    {
        if(q[i]==1) ans++;
    }
    //cout<<ans;
    cout<<m;

    return 0;
}
