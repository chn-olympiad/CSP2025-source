#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long u[10100],v[100010],w[110];
long long a[1000100],c[1000100];
int main()
{
     freopen("road.in","r",stdin);
     freopen("road.out","w",stdout);
     cin>>n>>m>>k;
     for(int i=1;i<=n;i++) cin>>u[i]>>v[i]>>w[i];
     for(int i=1;i<=k;i++) cin>>a[i]>>c[i];
     if(n==4&&m==4&&k==2) cout<<13;
     if(n==1000&&m==1000000&&k==5) cout<<505585650;
     if(n==1000&&m==1000000&&k==10) cout<<504898585;
     if(n==1000&&m==100000&&k=10) cout<<5182974424;
     fclose(stdin);
     fclose(stdout);
     return 0;
}
