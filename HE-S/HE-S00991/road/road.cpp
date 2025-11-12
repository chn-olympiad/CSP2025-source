#include<bits/stdc++.h>
using namespace std;
int n,m,k;//城市 道路 乡镇 
long long lz[10005],ly[10005],w[100000005];
long long cz[105],xl[1000000005],cunzi[105],xz[10005],feiy[1000000005];
int cnt;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long a[m+1];
	for(int i=1;i<=m;i++){
		cin>>lz[i]>>ly[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>cz[i]>>xl[i]>>cunzi[i]>>xz[i]>>feiy[i];
	}
	for(int i=1;i<=n;i++){
		cnt+=w[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
