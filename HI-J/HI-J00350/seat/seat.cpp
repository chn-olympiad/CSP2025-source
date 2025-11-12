#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int a[110];
	int pos=0;
	for(int i=0;i<n*m;i++){
		cin>>a[i]; 
		if(i==0){
			pos=a[i];
		}
	}
	for(int i=0;i<n*m-1;i++){
		for(int j=i+1;j<n*m;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	int b[110][110];
	int pos2=0;
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				b[i][j]=a[pos2];
				pos2+=1;
			}
		}else{
			for(int j=1;j<=m;j++){
				b[i][j]=a[pos2];
				pos2+=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==pos){
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	return 0;
}
