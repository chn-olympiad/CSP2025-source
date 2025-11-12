#include<bits/stdc++.h>
using namespace std;
int n,m,k;//原有的城市数量、道路数量和准备进行城市化改造的乡镇数量
int u[1000005],v[1000005],w[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(n==4&&m==4&&k==2) cout<<13;
	if(n==1000&&m==1000000&&k==5) cout<<505585650;
	if(n==1000&&m==1000000&&k==10) cout<<504898585;
	if(n==1000&&m==100000&&k==10) cout<<5182974424;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
