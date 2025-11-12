#include<bits/stdc++.h>
using namespace std;
int l(int k,int j){
	return k>j;
}
long long d[1000000],f[1000000],g[1000000],z[10],x[10],c[10],w[100],s,m,a;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>a;
for(int i=1;i<=a;i++){
	cin>>m;
	for(int q=1;q<=a;q++){
	cin>>d[q]>>f[q]>>g[q];
	s+=d[q];
}
}
cout<<s;
return 0;
}
