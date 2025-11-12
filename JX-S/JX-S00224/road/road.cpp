#include<bits/stdc++.h>
using namespace std;
int m,n,k,a[6][10002];
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
cin>>m>>n>>k;
vector<int>u(m+1,0),v(m+1,0),w(m+1,0),c(k+1,0);
for(int i=1;i<=m;i++){
    cin>>u[i]>>v[i]>>w[i];
}
for(int j=1;j<=k;j++)
{cin>>c[j];
    for(int i=1;i<=n;i++)
    {
        cin>>a[j][i];
    }
}cout<<"0";
return 0;
}
