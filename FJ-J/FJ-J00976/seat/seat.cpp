#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],b[1000][1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		
	}
	int ff=a[1];
	int x=1;
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
				
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				b[i][j]=a[x++];if(ff==b[i][j]){
				cout<<i<<" "<<j;return 0;
			}
			}
		}
		if(i%2==0){
			for(int j=m;j>=1;j--){
				b[i][j]=a[x++];if(ff==b[i][j]){
				cout<<i<<" "<<j;return 0;
			}
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;}
	*/	

	return 0;
}
