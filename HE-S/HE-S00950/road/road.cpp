#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u[n],v[n],w[n];
	for(int i=0;i<n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	sort(w,w+n);
	int sum = 0;
	for(int i=0;i<n-1;i++){
		sum+=w[i];
	}
	cout<<sum;//666·þÁË É¶Òõ¼ä¡£¡£¡£ 
	return 0;
} 
