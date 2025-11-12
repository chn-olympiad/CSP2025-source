#include<iostream>
#include<algorithm>
using namespace std;
int a[11],b[11][11];
int main(){
	//freopen("seat.in");
	//freopen("seat.out");
	int n,m,k,cnt,ant;
	cin>>n>>m;
	ant=n*m;
	for(int i=1;i<=ant;i++){
		cin>>a[i]; 
	}
	k=a[1];
	sort(a+1,a+ant+1);
	for(int i=1;i<=m;i++){
		cnt++;
		if(cnt%2==1){
			for(int j=1;j<=n;j++){
				b[i][j]=a[ant];
				ant--;
			} 
		}else{
			for(int j=n;j>=1;j--){
				b[i][j]=a[ant];
				ant--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==k){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
} 
