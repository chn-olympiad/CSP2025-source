#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],x[105][105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]); 
			}
		}
	}
	int s=1;
	for(int i=1;i<=m;i++){
		if(i%2==0){
		    for(int j=n;j>=1;j--){
			    x[i][j]=a[s];
			    s++;
		    }
		}
		else{
			for(int j=1;j<=n;j++){
				x[i][j]=a[s];
				s++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(x[i][j]==r){
				cout<<i<<' '<<j;
			}
		}
	}
	return 0;
}
