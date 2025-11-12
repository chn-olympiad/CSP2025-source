#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[11][11],n,m,i,j,R;
	cin>>n>>m;
	int b[n*m];
	for(i=1;i<=n*m;i++){
		cin>>b[i];
	}
	R=b[1];
	for(i=1;i<=n*m;i++){
		for(j=1;j<=n*m-i;j++){
			if(b[j]>b[j-1])
				swap(b[j],b[j-1]);
		}
	}
	i=1;j=1;
	while(j<=n*m){
		if(j=n){
			j--;
			i++;	
		}	
		if(j=1){
			j++;
			i++;
		}
		a[i][j]=b[j];
		if(a[i][j]=R){
			cout<<i<<" "<<j;
			break;
		}
	}
	return 0;
}