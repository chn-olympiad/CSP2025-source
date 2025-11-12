#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,g;
	cin >> n >> m;
	bool b=true;
	int a[n][m];
	int v[100000];
	for(g=0;g<n*m;g++){
		cin >> v[g];
	}
	int aim=v[0];
	while(b){
		b=false;
		for(int k=0;k<g;k++){
			int connect;
			if(v[k]<v[k+1]){
				connect=v[k];
				v[k]=v[k+1];
				v[k+1]=connect;
				b=true;
			}
		}
	}
	for(int i=0;i<m;i++){
		if((i+1)%2==0){
			for(int j=0;j<n;j++){
				a[j][i]=v[(i+1)*n-1-j];
			}
		}
		else{
			for(int j=0;j<n;j++){
				a[j][i]=v[i*n+j];
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[j][i]==aim){
			    cout << i+1 << " " << j+1;
			}
		}
	}
	return 0;
}
