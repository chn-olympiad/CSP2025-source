#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int h=n*m;
	for(int i=0;i<h;i++){
		cin>>a[i];
	}
	int l=a[0];
	for(int i=0;i<h;i++){
		for(int j=0;j<h;j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	int k=0;
	for(int i=0;i<n;i++){
		if(i%2==0){
			for(int j=0;j<m;j++){
				b[j][i]=a[k++];
			}
		}else{
			for(int j=m-1;j>=0;j--){
				b[j][i]=a[k++];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(b[i][j]==l){
				cout<<j+1<<" "<<i+1;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 