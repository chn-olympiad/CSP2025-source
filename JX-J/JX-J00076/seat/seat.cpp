#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],b[12][12],k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int xr=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++) {
		if(a[i]<a[j]){
			swap(a[i],a[j]);
		 }
		}
	}
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--) {
			k++;
			if(a[k]==xr) cout<<i<<" "<<j;	
		}
		}
		else for(int j=1;j<=m;j++) {
			k++;	
			if(a[k]==xr) cout<<i<<" "<<j;	
		}
	}

}
