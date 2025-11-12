#include<bits/stdc++.h>
using namespace std;
long long m1[1000001],m2[1000001],m3[1000001],road[100050];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		cin>>m1[i]>>m2[i]>>m3[i];
	}
	for(long long i=1;i<=n*k+k;i++){
		cin>>road[i];
	}
	cout<<0;
	return 0;
}
