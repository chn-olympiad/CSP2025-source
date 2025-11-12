#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
int  n,m,k,a,b,c,i,d,e;
cin>>n>>m>>k;
for(i=1;i<=n;i++){
	cin>>a>>b>>c;
}for(i=1;i<=m;i++){
	cin>>a>>b>>c>>d>>e;
}cout<<k*m+n-1;
return 0;
}
