#include<bits/stdc++.h>
using namespace std;
int a[205][4],p[205][205][205];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int  T;
    cin>>T;
    while(T--)
    {
    int n,maxn=-1;
    cin>>n;
    if(n>200)
    {
        cout<<"0\n";
        continue;
    }
    memset(p,-1,sizeof p);
    p[0][0][0]=0;
    for(int i=1;i<=n;i++)
        cin>>a[i][1]>>a[i][2]>>a[i][3];
    for(int s=1;s<=n;s++)
    {
        for(int i=0;i<=min(s,n/2);i++)
            for(int j=0;i+j<=s&&j<=min(s,n/2);j++)
            {
                int k=s-i-j;
                if(k>min(s,n/2))
                    continue;
                if(i!=0)
                    p[i][j][k]=max(p[i][j][k],p[i-1][j][k]+a[s][1]);
                if(j!=0)
                    p[i][j][k]=max(p[i][j][k],p[i][j-1][k]+a[s][2]);
                if(k!=0)
                    p[i][j][k]=max(p[i][j][k],p[i][j][k-1]+a[s][3]);
                if(s==n)
                    maxn=max(maxn,p[i][j][k]);
            }
    }
    cout<<maxn<<'\n';
    }
}