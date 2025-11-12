//GZ-S00256 杨俊毅 遵义市南白初级中学 
#include <bits/stdc++.h>
using namespace std;
long long n,m,k,u[1000005],v[1000005],w[1000005],p;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
cin>>n>>m>>k;
for(int i=1;i<=m;i++){
	cin>>u[i]>>v[i]>>w[i];
	p+=min(w[i],min(u[i],v[i]));
}
//???免费修路 
cout<<p;
	fclose(stdin);
	fclose(stdout);
}

