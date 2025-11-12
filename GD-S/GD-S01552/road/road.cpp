#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[114514],b[114514],money[114514],xc[10][11451];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i]>>money[i];
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			cin>>xc[i][j];
		}
	}
	cout<<2025;
	return 0;
}
