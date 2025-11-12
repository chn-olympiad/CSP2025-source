#include<bits/stdc++.h>
using namespace std;
int n,m;
int maps[15][15];
int a[225];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	int Ra=a[0];
	
	sort(a,a+(n*m));
	 
	int kx=1,ky=1,k=n*m-1;
	maps[ky][kx]=a[k];
	k--;
	
	while(maps[ky][kx]!=Ra&&kx<=m){
		if(kx%2==1){
			if(ky<n){
				ky++;
			}else{
				kx++;
			}
			maps[ky][kx]=a[k];
			k--;
		}else{
			if(ky>1){
				ky--;
			}else{
				kx++;
			}
			maps[ky][kx]=a[k];
			k--;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<maps[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	
	cout<<kx<<' '<<ky;
	return 0;
}
