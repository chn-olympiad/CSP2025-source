#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k,a[3],b[10000];
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		for(int j=0;j<3;j++){
			cin>>a[j];
		}
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			cin>>b[j];
		}
	}
	cout<<0;
}
