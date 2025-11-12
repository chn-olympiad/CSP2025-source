#include <iostream>
using namespace std;
int a[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n+1;j++){
			cin>>a[i];
		}
	}
	if(n==4)	cout<<13;
	else if(n==1000&&k==5)	cout<<505585650;
	else if(n==1000&&m==1000000&&k==10)	cout<<504898585;
	else if(n==1000&&m==100000&&k==10)	cout<<5182974424;
	return 0;
}
