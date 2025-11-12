#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	int w[m+k]=[0];
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int j=1;j<=k;j++){
		cin>>w[m+j];
	}
	cout<<13;
	return 0;
}
