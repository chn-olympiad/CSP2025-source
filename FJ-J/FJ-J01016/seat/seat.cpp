#include<iostream>
using namespace std;

int n,m,o,x,y;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	o=a[0];
	for(int i=0;i<n*m-1;i++){
		for(int j=i+1;j<n*m;j++){
			if(a[j]>a[j-1]){
				int t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i]==o){
			i++;
			if(i%n!=0){
				x=i/n+1;
			}else{
				x=i/n;
			}
			y=i%n;
			if(y==0){
				y=n;
			} 
			if(x%2==0){
				y=n-y+1;
			}
			cout<<x<<' '<<y;
			return 0;
		}
	}
	return 0;
}
