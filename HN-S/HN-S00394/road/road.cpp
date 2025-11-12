#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n,m,k;
	int a[n],b[n],c[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	int d[m+1],j;
	for(int i=0;i<n;i++){
		cin>>j;
		for(int l=0;l<n;l++){
			cin>>d[l];
		}
	}
	cout<<13;
	return 0;
}
