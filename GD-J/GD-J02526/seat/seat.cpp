#include<iostream>
using namespace std;
int a[10000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int R;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	R=a[0];
	for(int i=0;i<n*m;i++){
		int max=0;
		for(int j=1;j<n*m;j++){
			if(a[j]>a[j-1]){
				max=a[j];
				a[j]=a[j-1];
				a[j-1]=max;
			}
		}
	}
	int jieg,y,z;
	for(int i=0;i<n*m;i++){
		if(a[i]=R){
			jieg=i%n;
			y=i/n;
			if(y%2==0){
				jieg=n-jieg;
			}
			
		}
	} 
	cout<<y+1<<" "<<jieg+1;
}
