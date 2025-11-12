#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
unsigned long long n,q,aa[maxn],bb[maxn],k=131,kk[maxn],xx[maxn],yy[maxn],ans;
string a[maxn],b[maxn],x,y;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    kk[0]=1;
    for(int i=1;i<maxn;i++)kk[i]=kk[i-1]*k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        for(int j=0;j<a[i].size();j++)
        {
            aa[i]=aa[i]*k+a[i][j]-'a';
            bb[i]=bb[i]*k+b[i][j]-'a';
        }
    }
    while(q--)
    {
        ans=0;
        cin>>x>>y;
        for(int i=0;i<x.size();i++)
        {
            xx[i+1]=xx[i]*k+x[i]-'a';
            yy[i+1]=yy[i]*k+y[i]-'a';
        }
        for(int i=1;i<=n;i++)
        {
            int s=a[i].size();
            for(int j=1;j<=x.size()-s+1;j++)
            {
                if(xx[j+s-1]-xx[j-1]*kk[s]==aa[i]&&yy[j+s-1]-yy[j-1]*kk[s]==bb[i]&&xx[j-1]==yy[j-1])
                {
                    if(xx[x.size()]-xx[j+s-1]*kk[x.size()-j-s+1]==yy[x.size()]-yy[j+s-1]*kk[x.size()-j-s+1])
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
}