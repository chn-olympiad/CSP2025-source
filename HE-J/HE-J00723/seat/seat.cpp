#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,c;
	int a[n*m+1];
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(i==0){
			r=a[i];
		}
		for(int j=1;j<=n*m;j++){
			if(a[i-j+1]>a[i-j]){
				c=a[i-j];
				a[i-j]=a[i-j+1];
				a[i-j+1]=c;
			}
			if(a[i-j+1]<=a[i-j]){
				break;
			}
		}
	}
	for(int i=0;i<m*n;i++){
		if(r==a[i]){
			cout<<i/n+1<<" "<<i%n;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
