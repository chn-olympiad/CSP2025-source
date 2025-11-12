#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],b[maxn],d[maxn],t[2000005],k;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=b[i-1]^a[i];
    }
    memset(t,-0x3f,sizeof(t));
    t[0]=0;
    for(int i=1;i<=n;i++)
    {
        k=m^b[i];
        d[i]=max(d[i-1],t[k]+1);
        t[b[i]]=max(t[b[i]],d[i]);
    }
    cout<<d[n];
}