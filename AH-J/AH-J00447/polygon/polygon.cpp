#include<bits/stdc++.h>
using namespace std;
int counta(int a[5001],int vis[5001],int k,int m,int n,int f)
{
    long long s=0;
    int o=0;

    if(f==k){
        for(int i=1;i<=k;i++) s+=vis[i];
        sort(vis+1,vis+k+1);
        if(s>2*vis[k]) return 1;
        else return 0;
    }


    else if(f<k&&m==n) return 0;
    for(int i=m+1;i<=n;i++)
    {
        vis[f+1]=a[i];
        o=o+counta(a,vis,k,i,n,f+1)%998244353;
        o=o%998244353;
        vis[f+1]=0;

    }
    return o;

}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5001];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int vis[5001],sss=0;
    for(int k=3;k<=n;k++)
    {
        sss=sss+counta(a,vis,k,0,n,0);
        sss=sss%998244353;
    }

    cout<<sss;
    return 0;
}
