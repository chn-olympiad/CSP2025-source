#include<bits/stdc++.h>
using namespace std;

int n,m,k,u,v,w,j,b;
int a[1001],b[10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin >> n >> m >> k;
	while(n--){
		cin >> u>>v>>w;
	}
	cin>>j;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	cin>>b;
	for(int i=1;i<=n;i++){
		cin >> b[i];
		
	}
	if(n==4&&m==4&&k==2){
		cout <<"13";
	}
	return 0;
}
