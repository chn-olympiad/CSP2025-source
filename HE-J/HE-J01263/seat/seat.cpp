#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int r=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
			if(a[i]>a[j]&&i!=j){
				int m=a[i];
				a[i]=a[j];
				a[j]=m;
			}
		}
	}
	int x=0;
	for(int i=0;i<n*m;i++){
		if(r==a[i]){
			x=i;
		}
	}
	int s=0;
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				if(x==s){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
				s++;
			}
		}else if(i%2==1){
			for(int j=n-1;j>=0;j--){
				if(x==s){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
				s++;
			}
		}
	}
	return 0;
}
