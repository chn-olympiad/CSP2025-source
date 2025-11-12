#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,m,k,h=0;
    cin>>n>>m>>k;
    int a[n],c[n],b[m];
    for(int i=0;i<m;i++)
    {
    cin>>a[i]>>c[i]>>b[i];
    h=h+b[i];
    }
    int d[k+m+1];
    for(int i=0;i<k+m+1;i++)
    {
    cin>>d[i];
    }
    cout<<h;
    return 0;
}
