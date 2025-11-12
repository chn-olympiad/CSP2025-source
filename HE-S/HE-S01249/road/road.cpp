#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int c;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int a[n+2]={0};
	int c[k+2]={0};
	int u[m+5]={0},v[m+5]={0},w[m+5]={0};
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	sort(w,w+m);
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int k=1;k<=n;k++){
			cin>>a[k];
		}
	}
	int num=0;
	int z=0;
	for(int i=1;i<n;i++){
		z+=i;
	}
	for(int i=1;i<=z;i++){
		num+=w[i];
	}
	cout<<num;
	return 0;
}
