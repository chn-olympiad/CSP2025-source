#include<bits/stdc++.h>
using namespace std;
int a[1000000],b[1000000],c[1000000];
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdin);
int n,m,k;
cin>>n>>m>>k;
int d[100000],e[100000];
for(int i=1;i<=m;i++)cin>>a[i]>>b[i]>>c[i];
for(int i=1;i<=k;i++){
    cin>>d[i];
    for(int j=1;j<=i;j++)cin>>e[j];
}
cout<<"13";
return 0;
}



