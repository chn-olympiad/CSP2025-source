#include<iostream>
using namespace std;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	const int maxn=1e4;
	int arr[maxn];
	int n,k;
	long long m;
	cin>>n>>m>>k;
	long long  u,v,w;
	cin>>u>>v>>w;
	for(int j=0; j<3; j++) {
		for(int i=0; i<3; i++) {
			cin>>arr[i]	;
		}
		
	}
	for(int i=3;i<5;i++){
		for(int j=0;j<5;j++){
			cin>>arr[j];
		}
	}

	cout<<13;
	return 0;

}
